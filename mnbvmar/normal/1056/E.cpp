#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
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

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int kBase = 1 << 20;

int tree[kBase * 2];

int GetMin(int a, int b) {
  a += kBase; b += kBase;
  int res = min(tree[a], tree[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) { mini(res, tree[a + 1]); }
    if (b % 2 == 1) { mini(res, tree[b - 1]); }
    a /= 2; b /= 2;
  }
  return res;
}

using triple = tuple<int,int,int>;

// sortuje indeksy z 'src' do 'dest' po kluczu 'keys' z zakresu [0..K]
void ksRadixPass(const VI& src, VI& dest, int size, const VI& keys, int K){
  VI cnt(K+1, 0);
  for(int i = 0; i < size; i++) { cnt[keys[src[i]]]++; }
  int prefSum = 0;
  for(int i = 0; i <= K; i++){
    int tmp = cnt[i];
    cnt[i] = prefSum;
    prefSum += tmp;
  }
  for(int i = 0; i < size; i++){
    int& pos = cnt[keys[src[i]]];
    dest[pos] = src[i];
    pos++;
  }
}

// znajduje tablice sufiksowa src[0..n-1] z kluczy {1..K}^n do dest[]
// koniecznosc: src[n..n+2] = 0 oraz n >= 2
void ksSuffixArray(const VI& src, VI& dest, int N, int K){
  int n0 = (N + 2) / 3, n2 = N / 3,  n02 = n0 + n2;
  VI src12(n02 + 3, 0), dest12(n02 + 3, 0), src0(n0, 0), dest0(n0, 0);
  // tworzymy liste indeksow o resztach 1 i 2 mod 3
  int ptr = 0;
  for(int i = 0; i < N + (N % 3 == 1); i++) {
    if(i % 3 != 0) src12[ptr++] = i;
  }
  // sortujemy pozycyjnie reszty 1 i 2
  ksRadixPass( src12, dest12, n02, VI(src.begin()+2, src.end()), K);
  ksRadixPass(dest12,  src12, n02, VI(src.begin()+1, src.end()), K);
  ksRadixPass( src12, dest12, n02, src,                          K);
  // przyporzadkowujemy trojkom (poczynajac od indeksow) leksykograficzne numerki
  int numNames = 0;
  triple biggestTriple = triple(-1, -1, -1);
  for (int i = 0; i < n02; i++) {
    int pos = dest12[i];
    triple newTriple = triple(src[pos], src[pos+1], src[pos+2]);
    if (newTriple != biggestTriple) {
      numNames++;
      biggestTriple = newTriple;
    }
    if (pos % 3 == 1) {
      src12[pos / 3] = numNames;
    } else { 
      src12[pos / 3 + n0] = numNames;
    }
  }
  // rekurencja, gdy nie ma unikatowych nazw
  if (numNames < n02) {
    ksSuffixArray(src12, dest12, n02, numNames);
    // przyporzadkowujemy kolejnym wartosciom unikatowe nazwy
    for (int i = 0; i < n02; i++) { src12[dest12[i]] = i + 1; }
  } else {
    // mozna sobie stworzyc prosciutko tablice sufiksowa
    for (int i = 0; i < n02; i++) { dest12[src12[i] - 1] = i; }
  }

  // sortujemy sufiksy podzielne przez 3 po pierwszym znaczku
  ptr = 0;
  for (int i = 0; i < n02; i++)
    if (dest12[i] < n0) src0[ptr++] = 3 * dest12[i];
  ksRadixPass(src0, dest0, n0, src, K);
  // laczymy
  for (int p = 0, t = (N % 3 == 1), k=0; k < N; k++) {
    int i = dest12[t] < n0 ? dest12[t] * 3 + 1 : (dest12[t] - n0) * 3 + 2,
        j = dest0[p];

    bool take0;
    if (dest12[t] < n0) {
      take0 = MP(src[i], src12[dest12[t] + n0]) < MP(src[j], src12[j / 3]);
    } else {
      take0 = triple(src[i], src[i + 1], src12[dest12[t] - n0 + 1]) <
              triple(src[j], src[j + 1], src12[j / 3 + n0]);
    }

    if (take0) {
      dest[k] = i;
      t++;
      if (t == n02) {
        k++;
        while (p < n0) {
          dest[k] = dest0[p]; k++; p++;
        }
      }
    } else {
      dest[k] = j; p++;
      if (p == n0) {
        k++;
        while (t < n02) {
          if (dest12[t] < n0) {
            dest[k] = dest12[t] * 3 + 1;
          } else {
            dest[k] = (dest12[t] - n0) * 3 + 2;
          }
          k++; t++;
        }
      }
    }
  }
}

VI suffixArray(VI source) {
  int N = SZ(source), K = *max_element(ALL(source));
  if (N == 1) { return {0}; }
  for (int& v : source) { v++; }
  for (int i = 0; i < 3; i++) { source.PB(0); }
  VI result(N + 3);
  ksSuffixArray(source, result, N, K + 2);
  result.resize(N);
  return result;
}

struct SA {
  vector<pair<PII, int>> x;
  VI suf; // <- numery kolejnych sufiksow w porzadku leksykograficznym
  VI rank; // <- odwrotnosc tablicy sufiksowej (suf)
  VI lcp; // lcp[i] == lcp(suf[i-1],suf[i])
  int *z;
  int n;
  SA(int *z_, int n_) : z(z_), n(n_) {
    /* z[n] = -1; // straznik zaklada ze -1 nie wystepuje w z
    //ostroznie coby nic nie nadpisac    
    suf.resize(n); rank.resize(n); x.resize(n);
    R(i, n) { x[i] = {{z[i], 0}, i}; }
    mapuj();
    int krok = 1;
    while (krok < n) {
      R (i, n) { x[i] = {{rank[i], i + krok < n ? rank[i + krok] : -1}, i}; }
      mapuj();
      krok *= 2;
    }
    R(i, n) { suf[rank[i]] = i; } */

    suf = suffixArray(VI(z, z + n));
    rank.resize(n);
    R(i, n) { rank[suf[i]] = i; }
    
    //LCP - opcjonalnie
    lcp.resize(n);
    int k = 0;
    R(i, n) {
      int ak = rank[i];
      if(ak) { while (z[suf[ak] + k] == z[suf[ak - 1] + k]) k++; }
      lcp[rank[i]] = k;
      if(k) { k--; }
    }
    debug(lcp);

    for (int i = 0; i < n; ++i)
      tree[kBase + i] = lcp[i];
    for (int i = kBase - 1; i > 0; --i)
      tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    //koniec LCP
  };
  void mapuj() {
    sort(ALL(x));
    int id = 0;
    R (i, n) {
      if (i && x[i - 1].st != x[i].st) id++;
      rank[x[i].nd] = id;
    }
  }

  int common_len(int a, int b) {
    if (a == b) { return n - a; }
    debug(a, b);
    a = rank[a];
    b = rank[b];
    debug(a, b);
    if (a > b) { swap(a, b); }
    return GetMin(a + 1, b);

  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  string zo;
  string t;
  cin >> zo >> t;

  int N = SZ(zo);
  int M = SZ(t);

  const int c0 = count(ALL(zo), '0');
  const int c1 = N - c0;

  int *data = new int[M + 1];
  for (int i = 0; i < M; ++i)
    data[i] = t[i];
  SA sa(data, M);

  int ans = 0;

  for (int len_0 = 1;; ++len_0) {
    const int len_1 = (M - c0 * len_0) / c1;
    if (len_1 <= 0) { break; }
    if (c0 * len_0 + c1 * len_1 != M) { continue; }

    int ptr = 0;
    int pos[2] = {-1, -1};
    int lens[2] = {len_0, len_1};

    bool fail = false;

    for (char ch : zo) {
      const int x = ch - '0';
      if (pos[x] == -1) {
        pos[x] = ptr;
      } else {
        const int common = sa.common_len(pos[x], ptr);
        if (common < lens[x]) {
          fail = true;
          break;
        }
      }

      ptr += lens[x];
    }
    debug(pos[0], pos[1]);
    if (!fail) {
      if (len_0 == len_1 && sa.common_len(pos[0], pos[1]) >= len_0)
        fail = true;
    }

    if (!fail) {
      debug(len_0, len_1);
      ++ans;
    }

  }

  cout << ans << "\n";

  delete[] data;
}