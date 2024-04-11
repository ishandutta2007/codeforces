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

const int N = 500005;

int t, n;
vector<int> V[N];
int p[N];
int myValue[N];
int subSize[N];
int cnt[N];

void DFS(int w) {
    subSize[w] = 1;
    for (int u : V[w]) {
        DFS(u);
        subSize[w] += subSize[u];
    }
}

void solve(int w, int from, int to) {
    myValue[w] = to;
    to--;
    reverse(V[w].begin(), V[w].end());
    for (int u : V[w]) {
        solve(u, from, from + subSize[u] - 1);
        from += subSize[u];
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n + 1; i++) {
            V[i].clear();
            cnt[i] = 0;
        }
        bool bad = false;
        priority_queue<int> Q;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            if (p[i] == -1) {
                p[i] = i + 1;
            }
            while (cnt[i] > 0) {
                Q.pop();
                cnt[i]--;
            }
            if (!Q.empty() && -Q.top() < p[i]) {
                bad = true;
            }
            cnt[p[i]]++;
            Q.push(-p[i]);
            V[p[i]].push_back(i);
        }
        if (bad) {
            printf("-1\n");
            continue;
        }
        DFS(n + 1);
        solve(n + 1, 1, n + 1);
        for (int i = 1; i <= n; i++) {
            printf("%d ", myValue[i]);
        }
        printf("\n");
    }
    return 0;
}