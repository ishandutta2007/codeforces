#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 300005, MAX = 1e6 + 5;

int n, q;
int sieve[MAX];
int A[N];

int main() {
    
    int t;
    scanf("%d", &t);
    
    for (int i = 2; i <= MAX; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                sieve[j] = i;
            }
        }
    }
    
    while (t--) {
        map<int, int> cnt;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int w;
            set<int> facts;
            scanf("%d", &w);
            while (w > 1) {
                int x = sieve[w];
                if (facts.count(x)) {
                    facts.erase(x);
                } else {
                    facts.insert(x);
                }
                w /= x;
            }
            int val = 1;
            for (auto x : facts) {
                val *= x;
            }
            A[i] = val;
            cnt[val]++;
        }
        int ans0 = 0;
        int ans1 = 0;
        for (int i = 1; i <= n; i++) {
            int ile = cnt[A[i]];
            ans0 = max(ans0, ile);
            if (ile % 2 == 0) A[i] = 1;
        }
        cnt.clear();
        for (int i = 1; i <= n; i++) {
            int w = A[i];
            set<int> facts;
            while (w > 1) {
                int x = sieve[w];
                if (facts.count(x)) {
                    facts.erase(x);
                } else {
                    facts.insert(x);
                }
                w /= x;
            }
            int val = 1;
            for (auto x : facts) {
                val *= x;
            }
            A[i] = val;
            cnt[val]++;
        }
        for (int i = 1; i <= n; i++) {
            int ile = cnt[A[i]];
            ans1 = max(ans1, ile);
        }
        scanf("%d", &q);
        while (q--) {
            long long x;
            scanf("%lld", &x);
            if (x > 0) {
                printf("%d\n", ans1);
            } else {
                printf("%d\n", ans0);
            }
        }
    }
    
    return 0;
}