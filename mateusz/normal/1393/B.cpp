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

int n, x, q;
char type;

set<pair<int, int> > pairs;
long long goodPairs = 0;
int cnt[100005];

void insert(int x) {
    pairs.erase({cnt[x], x});
    goodPairs -= cnt[x] / 2;
    cnt[x]++;
    goodPairs += cnt[x] / 2;
    pairs.insert({cnt[x], x});
}

void remove(int x) {
    pairs.erase({cnt[x], x});
    goodPairs -= cnt[x] / 2;
    cnt[x]--;
    goodPairs += cnt[x] / 2;
    pairs.insert({cnt[x], x});
}

bool query() {
    if (pairs.empty()) return false;
    return (--pairs.end())->first >= 4 && goodPairs - 2 >= 2;
}

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        insert(x);
    }
    
    scanf("%d", &q);
    while (q--) {
        scanf(" %c %d", &type, &x);
        if (type == '+') {
            insert(x);
        } else {
            remove(x);
        }
        printf(query() ? "YES\n" : "NO\n");
    }
    
    return 0;
}