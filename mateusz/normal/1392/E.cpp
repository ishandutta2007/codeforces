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

int n, q;
long long A[30][30];
int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int bit = i + j;
            int value = j % 2;
            if (value) {
                A[i][j] |= (1LL << bit);
            }
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        vector<pair<int, int> > cells;
        int x = 0;
        int y = 0;
        int step = 0;
        while (x != n - 1 || y != n - 1) {
            step++;
            cells.push_back({x, y});
            if (k & (1LL << step)) {
                if (y % 2 == 1) {
                    x++;
                } else {
                    y++;
                }
            } else {
                if (y % 2 == 0) {
                    x++;
                } else {
                    y++;
                }
            }
        }
        cells.push_back({x, y});
        for (auto p : cells) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
    
    
    return 0;
}