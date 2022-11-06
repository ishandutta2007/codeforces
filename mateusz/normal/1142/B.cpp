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

const int N = 200005, LOG = 18, BASE = (1 << 18);

int tree[2 * BASE + 5];
int n, m, q, per[N], nxt[N], jump[LOG + 5][N];
int A[N];
int last[N];

void insert(int pos, int w) {
    pos += BASE;
    while (pos >= 1) {
        tree[pos] = min(tree[pos], w);
        pos /= 2;
    }
}

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int ret = min(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = min(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = min(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int getPos(int from, int len) {
    for (int log = LOG; log >= 0; log--) {
        if ((1 << log) <= len) {
            len -= (1 << log);
            from = jump[log][from];
        }
    }
    return from;
}

int main() {
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (int i = 1; i <= 2 * BASE; i++) tree[i] = m + 1;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &per[i]);
    }
    
    for (int i = 0; i < n; i++) {
        nxt[per[i]] = per[(i + 1) % n];
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        last[i] = m + 1;
    }
    
    for (int log = 0; log <= LOG; log++) {
        jump[log][m + 1] = m + 1;
    }
    for (int i = m; i >= 1; i--) {
        int w = A[i];
        jump[0][i] = last[nxt[w]];
        last[w] = i;
    }
    
    for (int log = 1; log <= LOG; log++) {
        for (int i = 1; i <= m; i++) {
            jump[log][i] = jump[log - 1][jump[log - 1][i]];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int x = getPos(i, n - 1);
        debug(i, x);
        insert(i, x);
    }
    
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (query(l, r) <= r) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    
    return 0;
}