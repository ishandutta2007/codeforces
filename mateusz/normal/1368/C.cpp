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
int n, x;
int A[N];
int main() {
    
    scanf("%d", &n);
    
    vector<pair<int, int>> ans;
    for (int i = 1; i <= 2 * n + 1; i++) {
        ans.push_back({i, 0});
    }
    
    for (int i = 2; i <= 2 * n; i += 2) {
        ans.push_back({i, 1});
    }
    
    for (int i = 2; i <= 2 * n; i += 2) {
        ans.push_back({i, -1});
    }
    
   
    
    ans.push_back({0, 0});
    ans.push_back({0, 1});
    ans.push_back({0, 2});
    ans.push_back({1, 2});
    ans.push_back({2, 2});
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            ans.push_back({2 * i, -2});
            ans.push_back({2 * i + 1, -2});
            ans.push_back({2 * i + 2, -2});
        } else {
            ans.push_back({2 * i, 2});
            ans.push_back({2 * i + 1, 2});
            ans.push_back({2 * i + 2, 2});
            
        }
    }
    
    if (n % 2 == 1) {
        ans.push_back({2 * n + 2, -1});
        ans.push_back({2 * n + 2, 0});
    } else {
        ans.push_back({2 * n + 2, 1});
        ans.push_back({2 * n + 2, 0});
        
    }
    
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}