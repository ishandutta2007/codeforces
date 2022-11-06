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

const int N = 205;

char word[N];
int n;
bool vis[N];
vector<int> V[N];
vector<int> ans;

void DFS(int w) {
    vis[w] = true;
    ans.push_back(w);
    for (int u : V[w]) {
        if (!vis[u]) DFS(u);
    }
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        ans.clear();
        for (int i = 0; i < 26; i++) {
            V[i].clear();
            vis[i] = false;
        }
        scanf("%s", &word[1]);
        n = strlen(word + 1);
        for (int i = 1; i <= n; i++) {
            word[i] -= 'a';
        }
        for (int i = 2; i <= n; i++) {
            V[word[i]].push_back(word[i - 1]);
            V[word[i - 1]].push_back(word[i]);
        }
        for (int i = 0; i < 26; i++) {
            sort(V[i].begin(), V[i].end());
            V[i].resize(unique(V[i].begin(), V[i].end()) - V[i].begin());
        }
        bool bad = false;
        for (int i = 0; i < 26; i++) {
            if (V[i].size() > 2) {
                printf("NO\n");
                bad = true;
                break;
            }
        }
        if (bad) continue;
        
        
//         printf("YES\n");
        for (int i = 0; i < 26; i++) {
            debug(i, V[i]);
            if (V[i].size() == 1 && !vis[i]) {
                DFS(i);
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (!vis[i] && !V[i].empty()) {
                printf("NO\n");
                bad = true;
                break;
            }
            if (!vis[i] && V[i].empty()) ans.push_back(i);
        }
        if (bad) continue;
        
        printf("YES\n");
        for (int x : ans) {
            printf("%c", (char)(x + 'a'));
        }
        printf("\n");
    }
    
    return 0;
}