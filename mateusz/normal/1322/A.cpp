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

const int N = 1000005;

int n;
char word[N];

int main() {
    
    scanf("%d", &n);
    scanf("%s", &word[1]);
    
    int mini = 0;
    int state = 0;
    int start = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (word[i] == '(') {
            state++;
        } else {
            state--;
        }
        mini = min(mini, state);
        if (state == 0) {
            if (mini < 0) {
                ans += i - start;
            }
            mini = 0;
            start = i;
        }
    }
    if (state != 0) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", ans);
    
    return 0;
}