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

const int N = 100005;

int n, m;
int row, col;
bool state[2][N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    int blocks = 0;
    while (m--) {
        scanf("%d %d", &row, &col);
        row--;
        int bad = 0;
        if (col > 1 && state[1 - row][col - 1]) {
            bad++;
        }
        if (state[1 - row][col]) {
            bad++;
        }
        if (col < n && state[1 - row][col + 1]) {
            bad++;
        }
        if (state[row][col]) {
            blocks -= bad;
        } else {
            blocks += bad;
        }
        state[row][col] ^= 1;
        printf(blocks == 0 ? "Yes\n" : "No\n");
    }
    
    return 0;
}