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

const int N = 300005, BASE = (1 << 19);

int n, p[N], q[N], whereIs[N];

struct Node {
    int open;
    int close;
};

Node tree[2 * BASE + 5];

Node merge(Node left, Node right) {
    Node ret;
    ret.open = right.open + max(0, left.open - right.close);
    ret.close = left.close + max(0, right.close - left.open);
    return ret;
}

void insert(int pos, int type) {
    pos += BASE;
    if (type == 0) {
        tree[pos].open++;
    } else {
        tree[pos].close++;
    }
    if (min(tree[pos].open, tree[pos].close) > 0) {
        tree[pos].open = 0;
        tree[pos].close = 0;
    }
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        whereIs[p[i]] = i;
    }
    
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
    }
    
    set<int> unused;
    int ptr = 1;
    for (int i = n; i >= 1; i--) {
        int pos = whereIs[i];
        insert(pos, 0);
        while (ptr <= n && tree[1].open > 0) {
            printf("%d ", i);
            int posQ = q[ptr++];
            insert(posQ, 1);
        }
    }
    
    printf("\n");
    
    return 0;
}