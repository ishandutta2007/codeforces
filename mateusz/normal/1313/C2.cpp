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

const int N = 500005;

int n, limit[N];
long long pref[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &limit[i]);
    }
    
    vector<pair<int, int> > s;
    s.push_back({0, 0});
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        int ile = 0;
        while (s.back().first > limit[i]) {
            ile += s.back().second;
            sum -= (long long)s.back().second * (s.back().first - limit[i]);
            s.pop_back();
        }
        s.push_back({limit[i], ile + 1});
        sum += limit[i];
        pref[i] = sum;
    }
    
    
    s.clear();
    s.push_back({0, 0});
    sum = 0;
    long long best = 0;
    int bestId = 0;
    for (int i = n; i >= 1; i--) {
        int ile = 0;
        while (s.back().first > limit[i]) {
            ile += s.back().second;
            sum -= (long long)s.back().second * (s.back().first - limit[i]);
            s.pop_back();
        }
        s.push_back({limit[i], ile + 1});
        sum += limit[i];
        if (sum + pref[i] - limit[i] > best) {
            best = max(best, sum + pref[i] - limit[i]);
            bestId = i;
        }
    }
    
    for (int i = bestId - 1; i >= 1; i--) {
        limit[i] = min(limit[i], limit[i + 1]);
    }
    
    for (int i = bestId + 1; i <= n; i++) {
        limit[i] = min(limit[i], limit[i - 1]);
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", limit[i]);
    }
    printf("\n");
    return 0;
}