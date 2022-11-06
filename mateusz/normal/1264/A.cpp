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

const int N = 400005;

int t, n, points[N];

void test() {
    scanf("%d", &n);
    points[0] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &points[i]);
    }
    
    vector<pair<int, int> > groups;
    int totalSize = 0;
    int curGroup = 0;
    for (int i = 1; i <= n; i++) {
        curGroup++;
        if (i == n || points[i] != points[i + 1]) {
            if (2 * (totalSize + curGroup) > n) {
                break;
            }
            groups.push_back({points[i], curGroup});
            totalSize += curGroup;
            curGroup = 0;
        }
    }
    
    if (groups.empty()) {
        printf("0 0 0\n");
        return;
    }
    int gold = groups[0].second;
    int silver = -1, bronze = 0;
    int sum = 0;
    for (int i = 1; i < groups.size(); i++) {
        sum += groups[i].second;
        if (sum > gold) {
            silver = sum;
            for (int j = i + 1; j < groups.size(); j++) {
                bronze += groups[j].second;
            }
            break;
        }
    }
    if (sum <= gold || bronze <= gold) {
        printf("0 0 0\n");
        return;
    }
    printf("%d %d %d\n", gold, silver, bronze);
}

int main() {
    
    scanf("%d", &t);
    
    while (t--) {
        test();
    }
    
    return 0;
}