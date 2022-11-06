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

int n, k;
int Size[N];
vector<int> sizes[N];
int limit[N];
vector<int> answer[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &Size[i]);
        sizes[Size[i]].push_back(i);
    }
    
    for (int i = 1; i <= k; i++) {
        scanf("%d", &limit[i]);
    }
    
    int buckets = 0;
    long long freeSpace = 0;
    long long sumPref = 0;
    priority_queue<pair<int, int> > Q;
    for (int i = k; i >= 1; i--) {
        freeSpace += (long long)buckets * (limit[i] - limit[i + 1]);
        while (sizes[i].size() > freeSpace) {
            buckets++;
            freeSpace += limit[i];
            Q.push({0, buckets});
        }
        for (int x : sizes[i]) {
            int w = Q.top().second;
            int spaceOcc = -Q.top().first;
            Q.pop();
            answer[w].push_back(x);
            Q.push({-(spaceOcc + 1), w});
            freeSpace--;
        }
    }
    
    printf("%d\n", buckets);
    for (int i = 1; i <= buckets; i++) {
        sort(answer[i].begin(), answer[i].end(), [&](int a, int b) { return Size[a] < Size[b]; });
        printf("%d ", answer[i].size());
        for (int x : answer[i]) {
            printf("%d ", Size[x]);
        }
        printf("\n");
    }
    
    return 0;
}