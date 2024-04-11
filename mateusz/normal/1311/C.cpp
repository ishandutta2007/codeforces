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

int n, m;
int p[N];
int restart[N];
char word[N];
int cnt[300], total[300];

void test() {
    scanf("%d %d", &n, &m);
    scanf("%s", &word[1]);
    for (int i = 1; i <= n; i++) {
        restart[i] = 0;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        cnt[i] = total[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
        restart[p[i]]++;
    }
    restart[n]++;
    
    for (int i = 1; i <= n; i++) {
        cnt[word[i]]++;
        while (restart[i]--) {
            for (int j = 'a'; j <= 'z'; j++) {
                total[j] += cnt[j];
            }
        }
    }
    
    for (int i = 'a'; i <= 'z'; i++) {
        printf("%d ", total[i]);
    }
    printf("\n");
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        test();
    }
    
    return 0;
}