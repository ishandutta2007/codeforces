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

const int N = 200005, P = 257, M = 1000000033;

int n;
char word[N];

int H[N], H2[N];
int zera[N];
int a, b, l, q;
int pot[N];

int main() {
    
    scanf("%d", &n);
    
    scanf("%s", &word[1]);
    
    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = (long long)pot[i - 1] * P % M;
    }
    
    for (int i = 1; i <= n; i++) {
        if (word[i] == '1') {
            H[i] = H[i - 1];
            H2[i] = H2[i - 1];
            zera[i] = zera[i - 1];
        } else {
            zera[i] = zera[i - 1] + 1;
            if (i % 2 == 0) {
                H[i] = ((long long)H[i - 1] * P + 1) % M;
                H2[i] = ((long long)H2[i - 1] * P + 2) % M;
            } else {
                H[i] = ((long long)H[i - 1] * P + 2) % M;
                H2[i] = ((long long)H2[i - 1] * P + 1) % M;
            }
        }
    }
    
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &a, &b, &l);
        long long ha, hb;
        if (a % 2 == b % 2) {
             ha = ((H[a + l - 1] - (long long)H[a - 1] * pot[zera[a + l - 1] - zera[a - 1]] % M) + M) % M;
             hb = ((H[b + l - 1] - (long long)H[b - 1] * pot[zera[b + l - 1] - zera[b - 1]] % M) + M) % M;
        } else {
             ha = ((H[a + l - 1] - (long long)H[a - 1] * pot[zera[a + l - 1] - zera[a - 1]] % M) + M) % M;
             hb = ((H2[b + l - 1] - (long long)H2[b - 1] * pot[zera[b + l - 1] - zera[b - 1]] % M) + M) % M;
        }
        printf(ha == hb ? "Yes\n" : "No\n");
    }
    
    return 0;
}