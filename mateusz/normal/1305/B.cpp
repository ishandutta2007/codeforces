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

int suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ')') {
            suf[i]++;
        }
        suf[i] += suf[i + 1];
    }
    
        vector<int> oneMove;
        int opened = 0;
       for (int i = 0; i < s.size(); i++) {
           if (opened >= suf[i]) break;
            if (s[i] == '(') {
                opened++;
            } 
            if (opened >= suf[i]) break;
        }
        if (opened == 0) {
            cout << 0 << endl;
            return 0;
        }
        
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') oneMove.push_back(i), cnt++;
            if (cnt == opened) break;
        }
        
        cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') oneMove.push_back(i), cnt++;
            if (cnt == opened) break;
        }
        sort(oneMove.begin(), oneMove.end());

    
    cout << 1 << endl;
        cout << oneMove.size() << endl;
        for (int x : oneMove) {
            cout << x + 1 << " ";
        }
        cout << endl;
    
    return 0;
}