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
int p[100005];

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    int first = p[2] > p[1] ? 1 : 0;
    int cnt = 0;
    vector<int> slopes;
    int dir = -1;
    for (int i = 2; i <= n; i++) {
        int curDir = p[i] > p[i - 1] ? 1 : 0;
        if (curDir != dir) {
            if (dir != -1) {
                slopes.push_back(cnt);
            }
            cnt = 0;
            dir = curDir;
        }
        cnt++;
    }
    
    if (cnt > 0) {
        slopes.push_back(cnt);
    }
    
    int mx = 0;
    for (int x : slopes) mx = max(mx, x);
    
    int cntMax = 0;
    for (int x : slopes) {
        if (x == mx) {
            cntMax++;
        }
    }
    
    if (cntMax >= 3 || cntMax == 1) {
        printf("0\n");
        return 0;
    }
    
    for (int i = 0; i + 1 < slopes.size(); i++) {
        if (slopes[i] != mx) {
            continue;
        }
        if ((slopes[i + 1] != mx || (first ^ (i % 2)) == 0)) {
            printf("0\n");
            return 0;
        }
        break;
    }
    
    if (mx % 2 == 1) {
        printf("0\n");
        return 0;
    }
    
    printf("1\n");
    
    return 0;
}