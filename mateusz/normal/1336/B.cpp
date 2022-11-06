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

const long long INF = 4 * 1000000000000000000LL;

int Size[3];
vector<long long> weights[3];

long long findThird(vector<long long>& red, vector<long long>& green, vector<long long>& blue, int i, int j) {
    long long ret = INF;
    auto pos = lower_bound(blue.begin(), blue.end(), (red[i] + green[j]) / 2) - blue.begin();
    
    for (int k = -2; k <= 2; k++) {
        int p = pos + k;
        if (p >= 0 && p < blue.size()) {
            ret = min(ret, (red[i] - green[j]) * (red[i] - green[j]) + (red[i] - blue[p]) * (red[i] - blue[p]) + (green[j] - blue[p]) * (green[j] - blue[p]));
        }
    }
    return ret;
}

long long solve(vector<long long>& red, vector<long long>& green, vector<long long>& blue) {
    long long ret = INF;
    int ptr = 0;
    for (int i = 0; i < red.size(); i++) {
        while (ptr < green.size() && green[ptr] <= red[i]) {
            ptr++;
        }
        for (int j = -2; j <= 2; j++) {
            int p = ptr + j;
            if (p >= 0 && p < green.size()) {
                ret = min(ret, findThird(red, green, blue, i, p));
            }
        }
    }
    return ret;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &Size[0], &Size[1], &Size[2]);
        
        for (int col = 0; col < 3; col++) {
            weights[col].clear();
            for (int i = 0; i < Size[col]; i++) {
                int w;
                scanf("%d", &w);
                weights[col].push_back(w);
            }
            sort(weights[col].begin(), weights[col].end());
        }
        long long ans = INF;
        vector<int> per{0, 1, 2};
        do {
            ans = min(ans, solve(weights[per[0]], weights[per[1]], weights[per[2]]));
        } while (next_permutation(per.begin(), per.end()));
        printf("%lld\n", ans);
    }
    return 0;
}