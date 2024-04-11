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

const int N = 200005;

int n, val[N];
int timeFind[N];
int t[N];
long long curHigh[N];

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &timeFind[i]);
        t[i] = i;
    }
    
    sort(t + 1, t + 1 + n, [&](int a, int b) {
        return val[a] < val[b];
    });
    
    
    
    long long cost = 0;
    
    priority_queue<pair<int, int> > Q;
    
    vector<int> ans;
    
    int mini = -1;
    for (int i = 1; i <= n;) {
        if (mini == -1) {
            mini = val[t[i]];
        }
        while (i <= n && val[t[i]] <= mini) {
            Q.push({timeFind[t[i]], t[i]});
            i++;
        }
        
        while (!Q.empty()) {
            int id = Q.top().second;
            Q.pop();
            cost += (long long)timeFind[id] * (mini - val[id]);
            mini++;
            
            while (i <= n && val[t[i]] <= mini) {
                Q.push({timeFind[t[i]], t[i]});
                i++;
            }
        }
        mini = -1;
    }
    
    printf("%lld\n", cost);
    
    return 0;
}