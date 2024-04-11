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

int n;

int readColor() {
    int col;
    cin >> col;
    return col;
}

void putColor(int x, int y, int col) {
    cout << col << " " << x << " " << y << endl;
}

int main() {
    
    cin >> n;
    
    vector<pair<int, int>> even, odd;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                even.push_back({i, j});
            } else {
                odd.push_back({i, j});
            }
        }
    }
    
    while (!even.empty() && !odd.empty()) {
        int c = readColor();
        if (c == 1 || c == 3) {
            putColor(odd.back().first, odd.back().second, 2);
            odd.pop_back();
        } else {
            putColor(even.back().first, even.back().second, 1);
            even.pop_back();
        }
    }
    
    if (!even.empty()) {
        while (!even.empty()) {
            int c = readColor();
            if (c == 1 || c == 2) {
                putColor(even.back().first, even.back().second, 3);
            } else {
                putColor(even.back().first, even.back().second, 1);
            }
            even.pop_back();
        }
    }
    if (!odd.empty()) {
        while (!odd.empty()) {
            int c = readColor();
            if (c == 1 || c == 2) {
                putColor(odd.back().first, odd.back().second, 3);
            } else {
                putColor(odd.back().first, odd.back().second, 2);
            }
            odd.pop_back();
        }
    }
    
    return 0;
}