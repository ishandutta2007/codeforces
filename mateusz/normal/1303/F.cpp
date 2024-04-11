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

const int N = 305, Q = 2000005, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int n, m, q;
int rep[N * N];
int x[Q], y[Q], c[Q];
vector<int> queries[N][N];
int spojne[Q];
int curColor[N][N];
int ans[Q];

int find(int w) {
    return rep[w] = rep[w] == w ? w : find(rep[w]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    rep[a] = b;
    return true;
}

int getId(int a, int b) {
    return 301 * a + b;
}

int main() {
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            queries[i][j].push_back(0);
        }
    }
    
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &x[i], &y[i], &c[i]);
        if (c[i] != curColor[x[i]][y[i]]) {
            int id = getId(x[i], y[i]);
            rep[id] = id;
            spojne[c[i]]++;
            curColor[x[i]][y[i]] = c[i];
            for (int j = 0; j < 4; j++) {
                int xx = x[i] + dx[j];
                int yy = y[i] + dy[j];
                if (min(xx, yy) <= 0 || min(n - xx, m - yy) < 0) continue;
                if (curColor[xx][yy] == c[i]) {
                    if (Union(id, getId(xx, yy))) {
                        spojne[c[i]]--;
                    }
                }
            }
        }
        ans[i] = spojne[c[i]];
        debug(i, ans[i]);
        queries[x[i]][y[i]].push_back(c[i]);
    }
    
    for (int i = 0; i <= c[q]; i++) {
        spojne[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rep[getId(i, j)] = getId(i, j);
            spojne[curColor[i][j]]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = getId(i, j);
            for (int k = 0; k < 4; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (min(xx, yy) <= 0 || min(n - xx, m - yy) < 0) continue;
                if (curColor[i][j] == curColor[xx][yy]) {
                    if (Union(id, getId(xx, yy))) {
                        spojne[curColor[i][j]]--;
                    }
                }
            }
        }
    }
    
    int totalSpojne = 0;
    for (int i = 0; i <= c[q]; i++) {
        totalSpojne += spojne[i];
    }
    
    for (int i = q; i >= 1; i--) {
        if (i == q || c[i] != c[i + 1]) {
            totalSpojne -= spojne[c[i]];
        }
        ans[i] += totalSpojne;
        queries[x[i]][y[i]].pop_back();
        int lastColor = queries[x[i]][y[i]].back();
        if (lastColor != curColor[x[i]][y[i]]) {
            curColor[x[i]][y[i]] = lastColor;
            int id = getId(x[i], y[i]);
            rep[id] = id;
            spojne[lastColor]++;
            totalSpojne++;
            
            for (int j = 0; j < 4; j++) {
                int xx = x[i] + dx[j];
                int yy = y[i] + dy[j];
                if (min(xx, yy) <= 0 || min(n - xx, m - yy) < 0) continue;
                if (curColor[xx][yy] == lastColor) {
                    if (Union(id, getId(xx, yy))) {
                        spojne[lastColor]--;
                        totalSpojne--;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}