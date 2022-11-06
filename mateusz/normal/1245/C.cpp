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

const int N = 100005, M = 1e9 + 7;

void add(int &w, int u) {
    w += u;
    if (w >= M) w -= M;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int n;
char word[N];
int fib[N];

int main() {
    
    scanf("%s", &word[1]);
    n = strlen(word + 1);
    
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        add(fib[i], fib[i - 1]);
        add(fib[i], fib[i - 2]);
    } 
    
    int ans = 1;
    int cntU = 0, cntN = 0;
    for (int i = 1; i <= n; i++) {
        if (word[i] == 'm' || word[i] == 'w') {
            printf("0\n");
            return 0;
        }
        if (word[i] == 'u') {
            cntU++;
        } else {
            ans = mul(ans, fib[cntU]);
            cntU = 0;
        }
        if (word[i] == 'n') {
            cntN++;
        } else {
            ans = mul(ans, fib[cntN]);
            cntN = 0;
        }
    }
    
    ans = mul(ans, fib[cntU]);
    ans = mul(ans, fib[cntN]);
    printf("%d\n", ans);
    
    return 0;
}