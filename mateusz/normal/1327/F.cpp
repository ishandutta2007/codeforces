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

#define isnum(ch) ('0'<=ch&&ch<='9')
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)

const int N = 500005, M = 998244353;
char _buf[100000],*_op(_buf),*_ed(_buf);
int n, m, k;
int condFrom[N], condTo[N], condVal[N];
int realBegin[N], realEnd[N], realVal[N];
// vector<int> begins[N], Ends[N], begins2[N];
int ones[N];
int t[N];
int pot[N];
vector<pair<pair<int, int>, int> > inters;

int mul(int w, int u) {
    return (long long)w * u % M;
}

int sum(int w, int u) {
    int ret = w + u;
    if (ret < 0) return ret + M;
    if (ret >= M) return ret - M;
    return ret;
}
inline int getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
int solve(int bit) {
    
    for (int i = 0; i <= n + 1; i++) {
//         begins[i].clear();
//         begins2[i].clear();
//         Ends[i].clear();
        ones[i] = 0;
    }
//     vector<pair<pair<int, int>, int> > inters;
    for (int i = 1; i <= m; i++) {
        realVal[i] = (condVal[i] >> bit) & 1;
        if (realVal[i]) {
            ones[condFrom[i]]++;
            ones[condTo[i] + 1]--;
        } else {
//             begins[condFrom[i]].push_back(i);
//             Ends[condTo[i]].push_back(i);
        }
    }
//     sort(inters.begin(), inters.end());

//     
    int realN = 0;
    int s = 0;
    int started = 0;
    int ret = 0;
    int ptr = 0;
    for (int i = 1; i <= n; i++) {
        
        while (ptr < inters.size() && inters[ptr].first.first == i && inters[ptr].first.second == 0) {
            if (realVal[inters[ptr].second] == 0) {
                realBegin[inters[ptr].second] = realN + 1;
                started++;
            }
            ptr++;
        }
        
        s += ones[i];
        if (s == 0) {
            realN++;
        }
        
        while (ptr < inters.size() && inters[ptr].first.first == i && inters[ptr].first.second == 1) {
            if (realVal[inters[ptr].second] == 0) {
                int x = inters[ptr].second;
                realEnd[x] = realN;
                started--;
                if (realBegin[x] > realEnd[x]) {
                    return 0;
                }
            }
            ptr++;
        }
    }
//     
    vector<pair<int, int> > intervals;
    for (int i = 1; i <= m; i++) {
        if (realVal[i] == 1) continue;
        intervals.push_back({realBegin[i], realEnd[i]});
    }
    sort(intervals.begin(), intervals.end(), [&](pair<int, int> a, pair<int, int> b) { if (a.first != b.first) { return a < b; }
        return a.second > b.second;
    });
//     for (int i = 1; i <= n; i++) {
//         for (int j = begins2[i].size() - 1; j >= 0; j--) {
//             intervals.push_back({i, begins2[i][j]});
//         }
//     }
//     
    vector<pair<int, int>> newIntervals;
    int earliestEnd = n + 2;
    for (int i = intervals.size() - 1; i >= 0; i--) {
        if (intervals[i].second >= earliestEnd) {
            continue;
        }
        newIntervals.push_back(intervals[i]);
        earliestEnd = min(earliestEnd, intervals[i].second);
    }
    
    intervals = newIntervals;
    reverse(intervals.begin(), intervals.end());
    
    
    for (int i = 0; i < intervals.size(); i++) {
        if (i == 0) {
            ret += intervals[i].first - 1;
        }
        if (i + 1 == intervals.size()) {
            ret += realN - intervals[i].second;
        }
        if (i + 1 < intervals.size()) {
            ret += max(0, intervals[i + 1].first - intervals[i].second - 1);
        }
    }
    if (intervals.empty()) {
        ret = realN;
    }
    
    vector<int> prefSum;
    vector<int> dp;
    int low = 0;
    for (int i = 0; i < intervals.size(); i++) {
        while (intervals[low].second < intervals[i].first) {
            low++;
        }
        int poc = intervals[i].first;
        int kon = intervals[i].second;
        if (low == i) {
            int res = mul(sum(pot[kon - poc + 1],-1), dp.empty() ? 1 : dp.back());
            prefSum.push_back(res);
            dp.push_back(res);
        } else {
            int res = mul(sum(pot[kon - intervals[i - 1].second], -1), dp.empty() ? 1 : dp.back());
            int ile = poc - 1 - max(intervals[low].first - 1, low == 0 ? 0 : intervals[low - 1].second);
            int part = pot[ile];
            int toAdd = sum(sum(prefSum.back(), -prefSum[low]), mul(part, mul(sum(pot[intervals[low].second - poc + 1], -1), low == 0 ? 1 : dp[low - 1])));
            prefSum.push_back(sum(prefSum.back(), res));
            dp.push_back(sum(res, toAdd));
        }
    }
    return mul(pot[ret], dp.empty() ? 1 : dp.back());
return 0;
}

int main() {
    
//     scanf("%d %d %d", &n, &k, &m);
    n = getint();
    k = getint();
    m = getint();
    
    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = mul(pot[i - 1], 2);
    }
    
    for (int i = 1; i <= m; i++) {
//         scanf("%d %d %d", &condFrom[i], &condTo[i], &condVal[i]);
        condFrom[i] = getint();
        condTo[i] = getint();
        condVal[i] = getint();
        inters.push_back({{condFrom[i], 0}, i});
        inters.push_back({{condTo[i], 1}, i});
    }
    sort(inters.begin(), inters.end());
    
    
    int ans = 1;
    for (int i = 0; i < k; i++) {
        ans = mul(ans, solve(i));
    }
    
    printf("%d\n", ans);
    
    return 0;
}