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
int cached[N];

int query(int w) {
    if (w < 1 || w > n) return 1000000000;
    if (cached[w]) return cached[w];
    cout << "? " << w << endl;
    cin >> cached[w];
    return cached[w];
}

int main() {
    
    srand(time(0));
    
    cin >> n;

    int low = 1;
    int high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = query(mid);
        int nxt = query(mid + 1);
        int prev = query(mid - 1);
        if (val < nxt && val < prev) {
            cout << "! " << mid << endl;
            return 0;
        }
        if (nxt < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    assert(false);
    
    return 0;
}