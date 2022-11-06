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

const int N = 100005;

int n, m, a, b;
long long h[N], p[N], w[N], l[N], initP[N];
vector<int> V[N];

bool DFS(int v, int par = -1) {
    long long sumW = 0, sumL = 0;
    for (int u : V[v]) {
        if (par == u) continue;
        if (!DFS(u, v)) return false;
        sumW += w[u];
        sumL += l[u];
    }
    
    if (sumW > w[v] || w[v] + l[v] - initP[v] != sumW + sumL) {
        debug(v, w[v], l[v], sumW, sumL, initP[v]);
        return false;
    }
    return true;
}

void cntSubtree(int v, int par = -1) {
    
    for (int u : V[v]) {
        if (par == u) continue;
        cntSubtree(u, v);
        p[v] += p[u];
    }
}


int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &p[i]);
            initP[i] = p[i];
            V[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &h[i]);
        }
        
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            V[a].push_back(b);
            V[b].push_back(a);
        }
        
        cntSubtree(1);
        
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            debug(i, p[i], h[i]);
            if ((p[i] + h[i]) % 2 != 0) {
                bad = true;
                break;
            }
            w[i] = (p[i] + h[i]) / 2;
            l[i] = p[i] - w[i];
            debug(i, w[i], l[i]);
            if (w[i] < 0 || l[i] < 0) {
                bad = true;
                break;
            }
        }
        debug(bad);
        if (bad || !DFS(1)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    
    return 0;
}