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

const int N = 105;

char board[N][N];

const int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
const int y[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 1; i <= 9; i++) {
            scanf("%s", &board[i][1]);
        }
        for (int i = 0; i < 9; i++) {
            board[x[i]][y[i]]++;
            if (board[x[i]][y[i]] > '9') {
                board[x[i]][y[i]] = '1';
            }
        }
        for (int i = 1; i <= 9; i++) {
            printf("%s\n", board[i] + 1);
        }
    }
    
    return 0;
}