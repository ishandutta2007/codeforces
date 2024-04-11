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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 1000005, M = 1021112333, P = 257;

int n;
char s[N];
int H[N], H2[N];
int pot[N];

int main() {
    
    pot[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        pot[i] = (long long)pot[i - 1] * P % M;
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", &s[1]);
        n = strlen(s + 1);
        
        int low = 1;
        int high = n;
        while (low <= high && s[low] == s[high]) {
            low++;
            high--;
        }
        
        if (low > high) {
            printf("%s\n", s + 1);
            continue;
        }
        
        char *t = s + low - 1;
        int len = high - low + 1;
        for (int i = 1; i <= len; i++) {
            H[i] = ((long long)H[i - 1] * P + t[i]) % M;
        }
        H2[len + 1] = 0;
        for (int i = len; i >= 1; i--) {
            H2[i] = ((long long)H2[i + 1] * P + t[i]) % M;
        }
        
        int best = 0;
        int kt = -1;
        for (int i = len; i >= 1; i--) {
            if (H[i] == ((H2[1] - (long long)H2[i + 1] * pot[i] % M) + M) % M) {
                best = i;
                kt = 1;
                break;
            }
        }
        
        for (int i = 1; i <= len; i++) {
            if (H2[i] == ((H[len] - (long long)H[i - 1] * pot[len - i + 1] % M) + M) % M) {
                if (len - i + 1 > best) {
                    kt = 2;
                    best = len - i + 1;
                }
                break;
            }
        }
        
        for (int i = 1; i < low; i++) {
            printf("%c", s[i]);
        }
        if (kt == 1) {
            for (int i = 1; i <= best; i++) {
                printf("%c", s[i + low - 1]);
            }
        } else {
            for (int i = 1; i <= best; i++) {
                printf("%c", s[high - best + i]);
            }
        }
        for (int i = high + 1; i <= n; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
        n++;
//         cerr << low << " " << best << endl;
//         printf("%d\n", 2 * (low - 1) + best);
    }
    
    return 0;
}