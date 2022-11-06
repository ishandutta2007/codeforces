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

int n, event[N];

int main() {
    
    scanf("%d", &n);
    set<int> started;
    set<int> wasThisDay;
    
    vector<int> ans;
    int lastDay = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &event[i]);
        if (event[i] < 0) {
            event[i] = -event[i];
            if (!started.count(event[i])) {
                printf("-1\n");
                return 0;
            }
            started.erase(event[i]);
        } else {
            if (wasThisDay.count(event[i])) {
                printf("-1\n");
                return 0;
            }
            wasThisDay.insert(event[i]);
            started.insert(event[i]);
        }
        if (started.empty()) {
            ans.push_back(i - lastDay);
            lastDay = i;
            wasThisDay.clear();
        }
    }
    
    if (!started.empty()) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}