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

int n;
char s[N], t[N];

int main() {
    
    scanf("%d", &n);
    
    scanf("%s", &s[1]);
    scanf("%s", &t[1]);
    int badOne = 0, badTwo = 0;
    vector<int> posA, posB;
    for (int i = 1; i <= n; i++) {
        if (s[i] == t[i]) continue;
        if (s[i] == 'a' && t[i] == 'b') {
            badOne++;
            posA.push_back(i);
        }
        if (s[i] == 'b' && t[i] == 'a') {
            badTwo++;
            posB.push_back(i);
        }
    }
    if ((badOne + badTwo) % 2 == 1) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", (badOne + badTwo) / 2 + badOne % 2);
    for (int i = 0; i < posA.size(); i += 2) {
        if (i + 1 < posA.size()) {
            printf("%d %d\n", posA[i], posA[i + 1]);
        } else {
            printf("%d %d\n", posA[i], posA[i]);
            printf("%d %d\n", posA[i], posB.back());
        }
    }

    for (int i = 0; i < posB.size(); i += 2) {
        if (i + 1 < posB.size()) {
            printf("%d %d\n", posB[i], posB[i + 1]);
        }
    }
    
    
    return 0;
}