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

const int N = 600005, BASE = (1 << 20);

int tree[2 * BASE + 5];

int n, m, a[N], myPos[N], mini[N], maxi[N];

void insert(int posa, int posb) {
    if (posa > posb) return;
    posa += BASE;
    posb += BASE;
    tree[posa]++;
    if (posa != posb) {
        tree[posb]++;
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            tree[posa + 1]++;
        }
        if (posb % 2 == 1) {
            tree[posb - 1]++;
        }
        posa /= 2;
        posb /= 2;
    }
}

int query(int pos) {
    pos += BASE;
    int ret = 0;
    while (pos >= 1) {
        ret += tree[pos];
        pos /= 2;
    }
    return ret;
}

int main() {
    
    scanf("%d %d", &n, &m);
    int nd = 0;
    for (int i = n; i >= 1; i--) {
        myPos[i] = ++nd;
    }
    for (int i = 1; i <= n; i++) {
        mini[i] = maxi[i] = i;
        tree[i + BASE] = n - i;
    }

    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        mini[x] = 1;
        maxi[x] = max(maxi[x], query(myPos[x]) + 1);
        insert(myPos[x], nd);
        myPos[x] = ++nd;
    }
    
    for (int i = 1; i <= n; i++) {
        maxi[i] = max(maxi[i], query(myPos[i]) + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", mini[i], maxi[i]);
    }
    
    
    
    return 0;
}