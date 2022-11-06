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

const int N = 100005;

int n, H, h[N];

bool fits(vector<int> heights) {
    long long sum = 0;
    for (int i = 1; i < heights.size(); i += 2) {
        sum += max(heights[i - 1], heights[i]);
    }
    if (heights.size() % 2 == 1) {
        sum += heights.back();
    }
    return sum <= H;
}

bool good(int k) {
    vector<int> heights;
    for (int i = 1; i <= k; i++) {
        heights.push_back(h[i]);
    }
    
    sort(heights.begin(), heights.end());
    bool ok = fits(heights);
    reverse(heights.begin(), heights.end());
    bool ok2 = fits(heights);
    return ok || ok2;
}

int main() {
    scanf("%d %d", &n, &H);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    
    int low = 1;
    int high = n;
    int res = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}