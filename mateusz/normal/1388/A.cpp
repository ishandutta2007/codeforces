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

int n;
int main() {
    
    vector<int> nearly;
    for (int i = 2; i <= 100; i++) {
        if (nearly.size() >= 7) {
            break;
        }
        vector<int> primes;
        int w = i;
        for (int j = 2; j <= i; j++) {
            while (w % j == 0) {
                primes.push_back(j);
                w /= j;
            }
        }
        if (primes.size() == 2 && primes[0] != primes[1]) {
            nearly.push_back(i);
        }
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        
        bool found = false;
        for (int i = 0; i < nearly.size(); i++) {
            for (int j = i + 1; j < nearly.size(); j++) {
                for (int k = j + 1; k < nearly.size(); k++) {
                    int a = nearly[i];
                    int b = nearly[j];
                    int c = nearly[k];
                    int x = n - a - b - c;
                    if (x == a || x == b || x == c || x <= 0) continue;
                    found = true;
                    printf("YES\n");
                    printf("%d %d %d %d\n", a, b, c, x);
                    break;
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) continue;
        printf("NO\n");
    }
    
    return 0;
}