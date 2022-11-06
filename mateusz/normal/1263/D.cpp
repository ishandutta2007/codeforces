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

const int N = 200005;

int n;
int rep[N];
int which[256];

int find(int w) { return rep[w] = rep[w] == w ? w : find(rep[w]); }

void Union(int a, int b) {
    rep[find(a)] = rep[find(b)];
}

int main() {
    
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        rep[i] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (which[s[j]] != 0) {
                Union(i, which[s[j]]);
            } else {
                which[s[j]] = i;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (rep[i] == i) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}