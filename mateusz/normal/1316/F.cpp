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

const int N = 600005, BASE = (1 << 20), M = 1e9 + 7;

int n, p[N], q, powa[N], invPow[N], delVal[N], addPos[N], delPos[N], val[N], pos[N];

int add(int w, int u) {
    int x = w + u;
    if (x >= M) {
        x -= M;
    }
    return x;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int powaer(int a, int k) {
    if (k == 0) return 1;
    return mul(powaer(mul(a, a), k / 2), k % 2 ? a : 1);
}

int inv(int w) {
    return powaer(w, M - 2);
}

struct Node {
    int eVal;
    int eMin;
    int eMax;
    int len;
};

Node tree[2 * BASE + 5];

Node makeLeaf(int w) {
    int len = w == 0 ? 0 : 1;
    return {0, mul(w, invPow[1]), mul(w, invPow[1]), len};
}

Node merge(Node left, Node right) {
    Node ret;
    ret.eVal = add(add(left.eVal, right.eVal), mul(left.eMax, right.eMin));
    ret.eMin = add(left.eMin, mul(right.eMin, invPow[left.len]));
    ret.eMax = add(mul(left.eMax, invPow[right.len]), right.eMax);
    ret.len = left.len + right.len;
    return ret;
}

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = makeLeaf(w);
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int query() {
    return tree[1].eVal;
}

int main() {
    
    scanf("%d", &n);
    
    vector<pair<pair<int, int>, int> > events;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        events.push_back({{p[i], 0}, -1});
    }
    
    scanf("%d", &q);
    
    powa[0] = 1;
    for (int i = 1; i <= n + q; i++) {
        powa[i] = mul(powa[i - 1], 2);
    }
    
    invPow[n + q] = inv(powa[n + q]);
    for (int i = n + q - 1; i >= 0; i--) {
        invPow[i] = mul(invPow[i + 1], 2);
    }
    
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &pos[i], &val[i]);
        delVal[i] = p[pos[i]];
        p[pos[i]] = val[i];
        events.push_back({{delVal[i], 1}, i});
        events.push_back({{val[i], 0}, i});
    }
    
    sort(events.begin(), events.end());
    
    int maxId = 0;
    int id = 0;
    int pocId = 0;
    for (int i = 0; i < events.size(); i++) {
        int w = events[i].first.first;
        int type = events[i].first.second;
        int queryId = events[i].second;
        if (i == 0 || events[i].first.first != events[i - 1].first.first) {
            pocId = id;
        }
        if (type == 0) {
            id++;
            maxId++;
            if (queryId == -1) {
                insert(id, w);
            } else {
                addPos[queryId] = id;
            }
        } else {
            pocId++;
            delPos[queryId] = pocId;
        }
    }
    
    printf("%d\n", query());
    
    for (int i = 1; i <= q; i++) {
        insert(delPos[i], 0);
        insert(addPos[i], val[i]);
        printf("%d\n", query());
    }
    
    
    return 0;
}