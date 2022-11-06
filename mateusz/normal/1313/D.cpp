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

const int N = 100005, K = 300;

int n, m, k, from[N], to[N];
int dp[2 * N][K];

bool cmp(int a, int b) {
    if (to[a] != to[b]) {
        return to[a] < to[b];
    }
    return a < b;
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    vector<pair<pair<int, int>, int>> events;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &from[i], &to[i]);
        events.push_back({{from[i] - 1, 1}, i});
        events.push_back({{to[i], 0}, i});
    }
    
    sort(events.begin(), events.end());
    
    int lastPosition = 0;
    int lastType = 0;
    int lastBit = 0;
    vector<int> openIntervals;
    for (int i = 0; i < events.size(); i++) {
        int pos = events[i].first.first;
        int type = events[i].first.second;
        int id = events[i].second;
        int l = openIntervals.size();
        for (int mask = 0; mask < (1 << l); mask++) {
            if (lastType == 0) {
                int mask1 = ((mask >> lastBit) << (lastBit + 1)) + (1 << lastBit) + (mask % (1 << lastBit));
                int mask2 = ((mask >> lastBit) << (lastBit + 1))+ (mask % (1 << lastBit));
                dp[i + 1][mask] = (__builtin_popcount(mask) % 2) * (pos - lastPosition) + max(dp[i][mask1], dp[i][mask2]);
            } else {
                int newMask = ((mask >> (lastBit + 1)) << lastBit) + (mask % (1 << lastBit));
                dp[i + 1][mask] = (__builtin_popcount(mask) % 2) * (pos - lastPosition) + dp[i][newMask];
            }
        }
        if (type == 0) { // Closing
            for (int j = 0; j < openIntervals.size(); j++) {
                if (openIntervals[j] == id) {
                    lastBit = j;
                    swap(openIntervals[j], openIntervals.back());
                    openIntervals.pop_back();
                    break;
                }
            }
            sort(openIntervals.begin(), openIntervals.end(), cmp);
        } else { // Openings
            openIntervals.push_back(id);
            sort(openIntervals.begin(), openIntervals.end(), cmp);
            for (int j = 0; j < openIntervals.size(); j++) {
                if (openIntervals[j] == id) {
                    lastBit = j;
                    break;
                }
            }
        }
        lastType = type;
        lastPosition = pos;
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << k); i++) {
        ans = max(ans, dp[events.size()][i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}