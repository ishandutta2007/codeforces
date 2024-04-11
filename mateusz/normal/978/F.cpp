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

const int N = 200005;

int n, m, a, b, ans[N], skill[N], t[N];
vector<int> V[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &skill[i]);
        t[i] = i;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    sort(t + 1, t + 1 + n, [&](int a, int b) { return skill[a] < skill[b]; });
    
    
    int lastSkill = -1;
    int equal = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int w = t[i];
        if (skill[w] != lastSkill) {
            cnt += equal;
            equal = 0;
        }
        equal++;
        ans[w] = cnt;
        for (int u : V[w]) {
            if (skill[u] < skill[w]) {
                ans[w]--;
            }
        }
        lastSkill = skill[w];
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}