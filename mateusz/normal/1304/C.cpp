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

const int N = 105;

int n;
long long m;
long long arrivalTime[N], lowTemp[N], highTemp[N];

void test() {
    scanf("%d %lld", &n, &m);
    long long lastTime = 0;
    long long minTemp = m;
    long long maxTemp = m;
    bool bad = false;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &arrivalTime[i], &lowTemp[i], &highTemp[i]);
        maxTemp = min(highTemp[i], maxTemp + arrivalTime[i] - lastTime);
        minTemp = max(lowTemp[i], minTemp - arrivalTime[i] + lastTime);
        lastTime = arrivalTime[i];
        if (maxTemp < minTemp) {
            bad = true;
        }
    }
    if (!bad && maxTemp >= minTemp) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) test();
    
    return 0;
}