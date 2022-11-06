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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005;

int n;
string seq[N];

int pos[N*5], neg[N*5];

int main() {
    
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        maxLen = max((int)maxLen, (int)seq[i].size());
        int mini = 0;
        int sum = 0;
        for (int j = 0; j < seq[i].size(); j++) {
            if (seq[i][j] == '(') sum++;
            else sum--;
            mini = min(mini, sum);
        }
        
        if (sum >= 0) {
            if (mini >= 0) {
                pos[sum]++;
            }
        } else {
            if (mini - sum >= 0) {
                neg[-sum]++;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= maxLen; i++) {
        ans += min(pos[i], neg[i]);
    }
    ans += pos[0] / 2;
    
    cout << ans << endl;
    
    return 0;
}