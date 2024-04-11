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

const int N = 300005;

int t, n, tab[N], last[N], first[N], rem[N], Prev[N];

void test() {
    scanf("%d", &n);
    set<int> cols;
    for (int i = 1; i <= n; i++) last[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        last[tab[i]] = i;
        cols.insert(tab[i]);
    }
    
    for (int i = n; i >= 1; i--) {
        first[tab[i]] = i;
    }
    
    vector<int> seq;
    seq.push_back(0);
    int best = 0;
    
    for (int i = 1; i <= n; i++) {
        if (last[i - 1] != 0) {
            Prev[i] = i - 1;
        } else {
            Prev[i] = Prev[i - 1];
        }
        debug(i, Prev[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (first[tab[i]] == i) {
            if (last[Prev[tab[i]]] < first[tab[i]]) {
                rem[tab[i]] = rem[Prev[tab[i]]] + 1;
            } else {
                rem[tab[i]] = 1;
            }
            best = max(best, rem[tab[i]]);
        }
//         if (last[tab[i]] == i) {
//             best
//             int res = rem[tab[i]];
//             if (seq.size() == res + 1) {
//                 seq.push_back(1e9);
//             }
//             seq[res + 1] = min(seq[res + 1], tab[i]);
//         }
    }
    printf("%d\n", cols.size() - best);
}

int main() {
    
    scanf("%d", &t);
    
    while (t--) test();
    
    return 0;
}