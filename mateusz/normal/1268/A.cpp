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

const int N = 200005;

int n, k;
char word[N], word2[N];

int main() {
    
    scanf("%d %d", &n, &k);
    
    scanf("%s", &word[1]);
    
    for (int i = 1; i <= k; i++) {
        word2[i] = word[i];
    }
    for (int i = k + 1; i <= n; i++) {
        word2[i] = word2[i - k];
    }
    
    bool greater = true;
    for (int i = 1; i <= n; i++) {
        if (word2[i] > word[i]) {
            break;
        }
        if (word2[i] < word[i]) {
            greater = false;
            break;
        }
    }
    
    if (greater) {
        printf("%d\n", n);
        printf("%s\n", word2 + 1);
        return 0;
    }
    
    for (int i = k; i >= 1; i--) {
        word2[i]++;
        if (word2[i] <= '9') {
            break;
        } else {
            word2[i] -= 10;
        }
    }
    
    if (word2[0] == 1) {
        for (int i = k; i <= n; i++) {
            word2[i] = word2[i - k];
        }
        printf("%d\n", n + 1);
        printf("%s\n", word2);
    } else {
        for (int i = k + 1; i <= n; i++) {
            word2[i] = word2[i - k];
        }
        printf("%d\n", n);
        printf("%s\n", word2 + 1);
    }
    
    return 0;
}