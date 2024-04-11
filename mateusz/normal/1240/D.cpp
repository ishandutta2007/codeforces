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
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 300005, P1 = 1000033, P2 = 1000037, M1 = 1015123189, M2 = 1015123201;

int t, n, tab[N];

long long solve(int from, int to) {
    if (from >= to) {
        return 0;
    }
    int mid = (from + to) / 2;
    long long solveLeft = solve(from, mid);
    long long solveRight = solve(mid + 1, to);
    
    vector<int> s;
    vector<int> hash, hash2;
    map<pair<int, int>, int> cnt;
    for (int i = mid; i >= from; i--) {
        int h1 = (hash.empty() ? 0 : hash.back());
        int h2 = (hash2.empty() ? 0 : hash2.back());
        if (s.empty() || s.back() != tab[i]) {
            s.push_back(tab[i]);
            int newHash = ((long long)h1 * P1 + tab[i]) % M1;
            int newHash2 = ((long long)h2 * P2 + tab[i]) % M2;
            hash.push_back(newHash);
            hash2.push_back(newHash2);
        } else if (!s.empty()) {
            hash.pop_back();
            hash2.pop_back();
            s.pop_back();
        }
        h1 = (hash.empty() ? 0 : hash.back());
        h2 = (hash2.empty() ? 0 : hash2.back());
        cnt[{h1, h2}]++;
    }
    
    s.clear();
    hash.clear();
    hash2.clear();
    long long ret = 0;
    for (int i = mid + 1; i <= to; i++) {\
        int h1 = (hash.empty() ? 0 : hash.back());
        int h2 = (hash2.empty() ? 0 : hash2.back());
        if (s.empty() || s.back() != tab[i]) {
            s.push_back(tab[i]);
            int newHash = ((long long)h1 * P1 + tab[i]) % M1;
            int newHash2 = ((long long)h2 * P2 + tab[i]) % M2;
            hash.push_back(newHash);
            hash2.push_back(newHash2);
        } else if (!s.empty()) {
            hash.pop_back();
            hash2.pop_back();
            s.pop_back();
        }
        h1 = (hash.empty() ? 0 : hash.back());
        h2 = (hash2.empty() ? 0 : hash2.back());
        ret += cnt[{h1, h2}];
    }
    return solveLeft + solveRight + ret;
}

void test() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    printf("%lld\n", solve(1, n));
    
}

int main() {
    
    scanf("%d", &t);
    
    while (t--) {
        test();
    }
    
    return 0;
}