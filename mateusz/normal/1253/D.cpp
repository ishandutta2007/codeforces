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

const int N = 200005;

int n, m, a, b;
int rep[N];
int size[N];

int find(int w) {
    return rep[w] = w == rep[w] ? w : find(rep[w]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) swap(a, b);
    size[b] += size[a];
    rep[a] = b;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) rep[i] = i;
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        Union(a, b);
        size[find(b)]++;
    }
    
    int last = -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i < last) {
            if (find(i) != last) {
                Union(i, last);
                ans++;
            }
        }
        last = max(last, find(i));
    }
    
    printf("%d\n", ans);
    
    return 0;
}