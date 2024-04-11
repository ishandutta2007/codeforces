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
int n, m;
char word[N];
int cnt[N], b[N];
bool vis[N];
int ans[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &word[1]);
        n = strlen(word + 1);
        for (int i = 'a'; i <= 'z'; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cnt[word[i]]++;
        }
        scanf("%d", &m);
        vector<int> zeros;
        for (int i = 1; i <= m; i++) {
            vis[i] = false;
            scanf("%d", &b[i]);
            if (b[i] == 0) {
                vis[i] = true;
                zeros.push_back(i);
            }
        }
        int last = 'z';
        while (!zeros.empty()) {
            int cur = -1;
            for (int i = last; i >= 'a'; i--) {
                if (zeros.size() <= cnt[i]) {
                    cur = i;
                    break;
                }
            }
            assert(cur != -1);
            vector<int> newZeros;
            for (auto x : zeros) {
                ans[x] = cur;
                for (int i = 1; i <= m; i++) {
                    b[i] -= abs(x - i);
                    if (b[i] == 0 && !vis[i]) {
                        newZeros.push_back(i);
                        vis[i] = true;
                    }
                }
            }
            zeros = newZeros;
            last = cur - 1;
        }
        
        for (int i = 1; i <= m; i++) {
            printf("%c", (char)ans[i]);
        }
        printf("\n");
    }
    
    return 0;
}