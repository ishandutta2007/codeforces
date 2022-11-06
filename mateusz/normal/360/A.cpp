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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 5005;

int type, a, b, c;
int n, m, mini[N], ans[N], cur[N], inc[N];

bool good(vector<pair<pair<int, int>, pair<int, int>>>& events) {
    for (int i = 1; i <= n; i++) {
        cur[i] = ans[i];
    }
    
    for (auto e : events) {
        int type = e.first.first;
        int a = e.first.second;
        int b = e.second.first;
        int c = e.second.second;
        if (type == 1) {
            for (int j = a; j <= b; j++) {
                cur[j] += c;
            }
        } else {
            int mx = -1e9;
            for (int j = a; j <= b; j++) {
                mx = max(mx, cur[j]);
            }
            if (mx != c) return false;
        }
    }
    return true;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        mini[i] = 1e9;
    }
    
    vector<pair<pair<int, int>, pair<int, int>>> events;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &type, &a, &b, &c);
        events.push_back({{type, a}, {b, c}});
        if (type == 1) {
            for (int j = a; j <= b; j++) {
                inc[j] += c;
            }
        } else {
            for (int j = a; j <= b; j++) {
                mini[j] = min(mini[j], c - inc[j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        ans[i] = mini[i];
    }
    
    if (good(events)) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
    } else {
        printf("NO\n");
    }
    
    
    return 0;
}