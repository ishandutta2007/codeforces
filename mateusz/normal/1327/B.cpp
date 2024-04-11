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

int n, isTaken[N];
int ile, w;

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            isTaken[i] = false;
        }
        int sad = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ile);
            bool found = false;
            for (int j = 0; j < ile; j++) {
                scanf("%d", &w);
                if (!isTaken[w] && !found) {
                    found = true;
                    isTaken[w] = true;
                }
            } 
            if (!found) {
                sad = i;
            }
        }
        if (sad == -1) {
            printf("OPTIMAL\n");
            continue;
        }
        for (int i = n; i >= 1; i--) {
            if (!isTaken[i]) {
                printf("IMPROVE\n%d %d\n", sad, i);
                break;
            }
        }
    }
    
    return 0;
}