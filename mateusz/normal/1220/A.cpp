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

int n, cnt[1005];

char word[N];

int main() {
    
    scanf("%d", &n);
    
    scanf("%s", &word[1]);
    
    for (int i = 1; i <= n; i++) {
        cnt[word[i]]++;
    }
    
    int zeros = 0;
    while (cnt['z'] && cnt['e'] && cnt['r'] && cnt['o']) {
        cnt['z']--;
        cnt['e']--;
        cnt['r']--;
        cnt['o']--;
        zeros++;
    }
    
    int ones = 0;
    while (cnt['o'] && cnt['e'] && cnt['n']) {
        cnt['e']--;
        cnt['n']--;
        cnt['o']--;
        ones++;
    }
    
    for (int i = 1; i <= ones; i++) {
        printf("1 ");
    }
    
    
    for (int i = 1; i <= zeros; i++) {
        printf("0 ");
    }
    
    printf("\n");
    
    return 0;
}