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

const int N = 1005;

int n, m;
string s[N];
bool done[N];

int main() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    
    int whoIsPal = -1;
    vector<int> beg, ending;
    for (int i = 1; i <= n; i++) {
        if (done[i]) {
            continue;
        }
        for (int j = i + 1; j <= n; j++) {
            if (done[j]) continue;
            string t = s[i];
            reverse(t.begin(), t.end());
            if (t == s[j]) {
                done[i] = done[j] = true;
                beg.push_back(i);
                ending.push_back(j);
            }
        }
        if (!done[i]) {
            string t = s[i];
            reverse(t.begin(), t.end());
            if (s[i] == t) {
                whoIsPal = i;
            }
        }
    }
    
    if (whoIsPal != -1) {
        beg.push_back(whoIsPal);
    }
    reverse(ending.begin(), ending.end());
    string ret;
    for (auto x : beg) {
        ret += s[x];
    }
    
    for (auto x : ending) {
        ret += s[x];
    }
    
    cout << ret.size() << endl;
    cout << ret << endl;
    
    return 0;
}