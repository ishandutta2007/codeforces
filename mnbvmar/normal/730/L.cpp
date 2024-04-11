#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 5e5 + 5;

const int Mod = 1e9 + 7;
string input;
vector<int> inv10, pwr10;

int powMod(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) { res = ((LL)res * a) % Mod; }
    n >>= 1;
    a = ((LL)a * a) % Mod;
  }
  return res;
}

int invMod(int a) { return powMod(a, Mod - 2); }

void preprocAll() {
  inv10.resize(MaxN);
  pwr10.resize(MaxN);
  inv10[0] = pwr10[0] = 1;
  inv10[1] = invMod(10);
  pwr10[1] = 10;
  for (int i = 2; i < MaxN; i++) {
    inv10[i] = ((LL)inv10[i - 1] * inv10[1]) % Mod;
    pwr10[i] = ((LL)pwr10[i - 1] * 10) % Mod;
  }
}


struct Expr {
  int from, to;
  int value;
  bool preprocessed;
  Expr *parent;
  
  Expr() : value(-1), preprocessed(false) {}
  
  virtual void preprocess() { throw 1; }
  virtual int doGetVal() { throw 1; }
  
  int getVal() {
    if (!preprocessed) { preprocess(); preprocessed = true; value = doGetVal(); }
    return doGetVal();
  }
  
  virtual int doGetVal(int, int) { throw 1; }
  
  int getVal(int a, int b) {
    if (!preprocessed) { preprocess(); preprocessed = true; }
    return doGetVal(a, b);
  }
};


struct ParentExpr : public Expr {
  vector<Expr *> elems;
  
  int findElemAt(int pos) {
    int left = -1, right = SZ(elems);
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (pos >= elems[mid]->from) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return left;
  }
};


struct Sum : public ParentExpr {
  vector<int> prefSums;
  
  void preprocess() {
    int len = SZ(elems);
    prefSums.resize(len + 1);
    
    for (int i = 1; i <= len; i++) {
      prefSums[i] = (prefSums[i - 1] + elems[i - 1]->getVal()) % Mod;
    }
  }
  
  int doGetVal() { return prefSums.back(); }
  int doGetVal(int a, int b) {
    if (a > b) { return 0; }
    if (a == from && b == to) { return getVal(); }
    int aPos = findElemAt(a), bPos = findElemAt(b);
    return ((LL)prefSums[bPos + 1] - prefSums[aPos] + Mod) % Mod;
  }
};


struct Product : public ParentExpr {
  vector<int> prefTree;
  int totalProd;
  //vector<int> prefProds;
  int base;
  
  void preprocess() {
    debug("prod preproc", from, to);
    int len = SZ(elems);
    base = 1;
    while (base < len) { base *= 2; }
    prefTree.resize(base * 2);
    
    for (int i = 0; i < len; i++) {
      debug(i, elems[i], elems[i]->from, elems[i]->to);
      prefTree[base + i] = elems[i]->getVal();
    }

    for (int i = base - 1; i > 0; i--) {
      prefTree[i] = ((LL)prefTree[2 * i] * prefTree[2 * i + 1]) % Mod;
    }

    totalProd = 1;
    for (int i = 0; i < len; i++) {
      totalProd = ((LL)totalProd * prefTree[base + i]) % Mod;
    }
  }
  
  int doGetVal() { return totalProd; }
  
  int doGetVal(int a, int b) {
    for (auto P : elems) {
      debug(P->from, P->to);
    }
    if (a > b) { return 1; }
    int aPos = findElemAt(a), bPos = findElemAt(b);
    debug(a, b, aPos, bPos, prefTree[aPos + base]);
    aPos += base;
    bPos += base;
    if (aPos == bPos) { return prefTree[aPos]; }
    int result = ((LL)prefTree[aPos] * prefTree[bPos]) % Mod;

    while (aPos / 2 != bPos / 2) {
      if (aPos % 2 == 0) { result = ((LL)result * prefTree[aPos + 1]) % Mod; }
      if (bPos % 2 == 1) { result = ((LL)result * prefTree[bPos - 1]) % Mod; }
      aPos /= 2; bPos /= 2;
    }
    return result;
  }
};


struct Number : public Expr {
  vector<int> prefSums;
  
  void preprocess() {
    int len = to - from + 1;
    prefSums.resize(len + 1);
    
    for (int i = 1; i <= len; i++) {
      int pos = from + i - 1;
      prefSums[i] = ((LL)prefSums[i - 1] * 10 + input[pos] - '0') % Mod;
    }
    debug("preproc!", this, from, to, prefSums.back());
  }
  
  int doGetVal() { debug("!", from, to); return prefSums.back(); }
  
  int doGetVal(int a, int b) {
    int bPos = b - from,
        aPos = a - from;
    LL result = prefSums[bPos + 1];
    result -= (LL)prefSums[aPos] * pwr10[bPos - aPos + 1];
    return (result % Mod + Mod) % Mod;
    //return ((LL)(prefSums[bPos + 1] - prefSums[aPos]) * inv10[aPos]) % Mod;
  }
};



Expr *lowestAt[MaxN];

int query(int L, int R) {
  if (input[L] != '(' && !isdigit(input[L])) { return -1; }
  if (input[R] != ')' && !isdigit(input[R])) { return -1; }

  Expr *lnum = lowestAt[L], *rnum = lowestAt[R];
  debug(lnum, rnum);
  if (!lnum || !rnum) { return -1; }
  if (lnum == rnum) {
    return lnum->getVal(L, R);
  }
  
  int lNumVal = lnum->getVal(L, lnum->to),
      rNumVal = rnum->getVal(rnum->from, R);
      
  debug(lNumVal, rNumVal);

  Product *lprod = (Product *)lnum->parent, *rprod = (Product *)rnum->parent;
  if (lprod == rprod) {
    LL result = lNumVal;
    result = ((LL)result * lprod->getVal(lnum->to + 2, rnum->from - 2)) % Mod;
    result = ((LL)result * rNumVal) % Mod;
    return result;
  }
  
  int lProdVal = lprod->getVal(lnum->to + 2, lprod->to),
      rProdVal = rprod->getVal(rprod->from, rnum->from - 2);
      
  debug(lProdVal, rProdVal);
      
  Sum *lsum = (Sum *)lprod->parent, *rsum = (Sum *)rprod->parent;
  if (lsum != rsum) { return -1; }
  debug(lprod->to, rprod->from);
  return ((LL)lNumVal * lProdVal +
              lsum->getVal(lprod->to + 2, rprod->from - 2) +
          (LL)rProdVal * rNumVal) % Mod;
}



int closeBrack[MaxN];

Expr *parseNum(int start, int end, Product *prod) {
  if (input[start] == '(') {
    return lowestAt[start];
  }
  
  Number *num = new Number();
  debug("num", start, end, prod, num);
  num->from = start;
  num->to = end;
  num->parent = prod;
  
  for (int i = start; i <= end; i++) {
    lowestAt[i] = num;
  }
  return num;
}

Product *parseProd(int start, int end, Sum *sum) {
  debug("prod", start, end, sum);
  Product *product = new Product();
  product->from = start;
  product->to = end;
  product->parent = sum;
  
  vector<int> endpoints{start - 1};
  int ptr = start;
  
  while (ptr < end) {
    if (closeBrack[ptr]) { ptr = closeBrack[ptr]; }
    if (input[ptr] == '*') { endpoints.push_back(ptr); }
    ptr++;
  }
  
  endpoints.PB(end + 1);
  
  int S = SZ(endpoints) - 1;
  for (int i = 0; i < S; i++) {
    Expr *child = parseNum(endpoints[i] + 1, endpoints[i + 1] - 1, product);
    product->elems.push_back(child);
    child->parent = product;
  }
  return product;
}


void parseSum(int start, int end) {
  debug("sum", start, end);
  Sum *sum = new Sum();
  sum->from = start;
  sum->to = end;
  
  vector<int> endpoints{start};
  int ptr = start + 1;
  while (ptr < end) {
    if (closeBrack[ptr]) {
      ptr = closeBrack[ptr];
    }
    if (input[ptr] == '+') { endpoints.push_back(ptr); }
    ptr++;
  }
  
  endpoints.push_back(end);
  int S = SZ(endpoints) - 1;
  for (int i = 0; i < S; i++) {
    sum->elems.push_back(parseProd(endpoints[i] + 1, endpoints[i + 1] - 1, sum));
  }
  
  lowestAt[start] = lowestAt[end] = sum;
}

void parse() {
  int N = SZ(input);
  vector<int> bracks;
  
  for (int i = 0; i < N; i++) {
    if (input[i] == '(') {
      bracks.PB(i);
    } else if (input[i] == ')') {
      int v = bracks.back();
      closeBrack[v] = i;
      bracks.pop_back();
      parseSum(v, i);
    }
  }
  
  assert(SZ(bracks) == 0);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  preprocAll();
  cin >> input;
  input = "(" + input + ")";
  parse();
  
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << query(L, R) << "\n";
  }
}