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

int n;
char wordA[N], wordB[N];
int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", &wordA[1]);
        scanf("%s", &wordB[1]);
        bool rev = false;
        int from = 1;
        int to = n;
        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            if (!rev) {
                if (wordA[to] == wordB[i]) {
                    to--;
                    continue;
                }
                if (wordA[from] == wordB[i]) {
                    ans.push_back(1);
                }
                ans.push_back(i);
                rev = true;
                from++;
            } else {
                if (wordA[from] != wordB[i]) {
                    from++;
                    continue;
                }
                if (wordA[to] != wordB[i]) {
                    ans.push_back(1);
                }
                ans.push_back(i);
                rev = false;
                to--;
            }
        

        }
        printf("%d ", ans.size());
        for (int x : ans) {
            printf("%d ", x);
        }
        printf("\n");
    }
    
    
    return 0;
}