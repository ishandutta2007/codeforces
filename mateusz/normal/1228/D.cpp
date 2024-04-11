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

const int N = 300005, P = 1035163, M = 1e9 + 7;

int n, m, a, b;
vector<int> V[N];
int Hash[N], assign[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    set<int> hashes;
    for (int i = 1; i <= n; i++) {
        sort(V[i].begin(), V[i].end());
        for (int u : V[i]) {
            Hash[i] = ((long long)Hash[i] * P + u) % M;
        }
        debug(i, Hash[i]);
        hashes.insert(Hash[i]);
    }
    
    if (hashes.size() != 3) {
        printf("-1\n");
        return 0;
    }
    
    int cnt = 0;
    for (int hashh : hashes) {
        cnt++;
        for (int i = 1; i <= n; i++) {
            if (Hash[i] == hashh) assign[i] = cnt;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", assign[i]);
    }
    printf("\n");
    
    return 0;
}