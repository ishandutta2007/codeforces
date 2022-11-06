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

const int N = 100005;

int n, x;
char word[N];
int balance[N];

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &x);
        scanf("%s", &word[1]);
        map<int, int> cntBal;
        cntBal[0]++;
        for (int i = 1; i <= n; i++) {
            word[i] -= '0';
            balance[i] = balance[i - 1] + (word[i] == 0 ? 1 : -1);
            cntBal[balance[i]]++;
        }
        int totalBal = balance[n];
        if (totalBal == 0) {
            if (cntBal.count(x)) {
                printf("-1\n");
            } else {
                printf("0\n");
            }
            continue;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int diff = x - balance[i];
            if (diff % totalBal == 0 && (long long)diff * totalBal >= 0) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}