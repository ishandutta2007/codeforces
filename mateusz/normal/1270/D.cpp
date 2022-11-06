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

const int N = 505;

pair<int, int> askFor(const set<int>& s) {
    cout << "? ";
    for (int x : s) {
        cout << x << " " ;
    }
    cout << endl;
    int pos, val;
    cin >> pos >> val;
    return make_pair(pos, val);
}

int main() {
    
    int n, k;
    cin >> n >> k;
    
    set<int> s;
    
    for (int i = 1; i <= k; i++) {
        s.insert(i);
    }
    
    auto p = askFor(s);
    int bestPos = p.first;
    int smallest = p.second;
    
    for (int i = k + 1; i <= n; i++) {
        s.erase(bestPos);
        s.insert(i);
        p = askFor(s);
        if (p.second > smallest) {
            s.erase(i);
            s.insert(bestPos);
        } else {
            bestPos = p.first;
            smallest = p.second;
        }
    }
    
    int anyOutside = -1;
    for (int i = 1; i <= n; i++) {
        if (!s.count(i)) {
            anyOutside = i;
            break;
        }
    }
    
    int cnt = 1;
    set<int> copyS = s;
    for (int x : copyS) {
        if (x == bestPos) {
            continue;
        }
        s.erase(x);
        s.insert(anyOutside);
        auto p = askFor(s);
        if (p.second > smallest) {
            cnt++;
        }
        s.erase(anyOutside);
        s.insert(x);
    }
    
    cout << "! " << cnt << endl;
    
    return 0;
}