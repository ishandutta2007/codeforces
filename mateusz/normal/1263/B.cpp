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

const int N = 100005;

char word[N][10];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        set<int> freeDigits[4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                freeDigits[i].insert(j);
            }
        }
        for (int i = 1; i <= n; i++) {
            scanf("%s", &word[i][0]);
            for (int j = 0; j < 4; j++) {
                freeDigits[j].erase(word[i][j] - '0');
            }
        }
        int cost = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                bool same = true;
                for (int k = 0; k < 4; k++) {
                    if (word[i][k] != word[j][k]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    cost++;
                    word[i][0] = *(freeDigits[0].begin()) + '0';
                    freeDigits[0].erase(freeDigits[0].begin());
                }
            }
        }
        printf("%d\n", cost);
        for (int i = 1; i <= n; i++) {
            printf("%s\n", word[i]);
        }
    }
    return 0;
}