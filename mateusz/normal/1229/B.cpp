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

const int N = 100005, M = 1e9 + 7;

int n, a, b;
long long beauty[N];
vector<int> V[N];
long long ans;

long long GCD(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return __gcd(a, b);
}

void DFS(int w, map<long long, int> cnt, int par = -1) {
    long long x = beauty[w];
    map<long long, int> cntNew;
    for (auto entry : cnt) {
        cntNew[GCD(x, entry.first)] += entry.second;
    }
    cntNew[x]++;
    for (auto entry : cntNew) {
        ans += (long long)entry.first * entry.second;
        ans %= M;
    }
    for (auto u : V[w]) {
        if (u != par) {
            DFS(u, cntNew, w);
        }
    }
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &beauty[i]);
    }
    
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1, {});
    
    printf("%lld\n", ans);
    
    return 0;
}