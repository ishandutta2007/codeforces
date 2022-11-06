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

const int N = 200005, A = 30;

int n, m, a, b;
char word[N];
int cnt[N][A];

int main() {
    
    scanf("%s", &word[1]);
    
    n = strlen(word + 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < A; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }
        cnt[i][word[i] - 'a']++;
    }
    
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &a, &b);
        if (b - a + 1 == 1 || word[a] != word[b]) {
            printf("Yes\n");
            continue;
        }
        int cntDiff = 0;
        for (int i = 0; i < A; i++) {
            if (cnt[b][i] - cnt[a - 1][i] > 0) {
                cntDiff++;
            }
        }
        printf(cntDiff > 2 ? "Yes\n" : "No\n");
    }
    
    return 0;
}