#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

/////////////////////////////////////////////////////////


const int MaxN = 200005,
          Base = (1 << 18),
          PSize = 2 * Base;

LL PTree[2][PSize];

void treeAdd(int id, int where, int val) {
  debug(id, where, val);
  where += Base;
  while (where) {
    PTree[id][where] += val;
    where /= 2;
  }
}

LL treeSum(int id, int L, int R) {
  debug(id, L, R);
  if (L > R) { return 0; }

  LL res = 0;
  L += Base; R += Base;
  res = PTree[id][L];
  if (L != R) { res += PTree[id][R]; }

  while (L/2 != R/2) {
    if (L % 2 == 0) { res += PTree[id][L + 1]; }
    if (R % 2 == 1) { res += PTree[id][R - 1]; }
    L /= 2; R /= 2;
  }
  return res;
}


int N, K, A, B, Q;
int curOrders[MaxN];

void input(){
  cin >> N >> K >> A >> B >> Q;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  input();

  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int day, amount;
      cin >> day >> amount;
      int incr0 = -min(A, curOrders[day]),
          incr1 = -min(B, curOrders[day]);

      curOrders[day] += amount;
      incr0 += min(A, curOrders[day]);
      incr1 += min(B, curOrders[day]);
      
      treeAdd(0, day, incr0);
      treeAdd(1, day, incr1);
    } else {
      int day;
      cin >> day;

      cout << treeSum(1, 0, day - 1) + treeSum(0, day + K, N + 1) << "\n";
    }
  }
}