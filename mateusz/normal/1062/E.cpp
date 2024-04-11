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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 100005, BASE = 131072, LOG = 17;

int n, m, a, b, q, timer;
int depth[N];
vector<int> V[N];
int jump[N][LOG + 5];
int inOrder[N], outOrder[N];

pair<int, int> minIntTree[2 * BASE + 5], maxIntTree[2 * BASE + 5];
int lcaTree[2 * BASE + 5];

void DFS(int w) {
    inOrder[w] = ++timer;
    for (int i = 1; i <= LOG; i++) {
        jump[w][i] = jump[jump[w][i - 1]][i - 1];
    }
    
    for (int u : V[w]) {
        depth[u] = depth[w] + 1;
        DFS(u);
    }
    outOrder[w] = ++timer;
}

bool isAncestor(int w, int u) {
    return inOrder[w] <= inOrder[u] && outOrder[w] >= outOrder[u];
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = LOG; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = jump[a][i];
        }
    }
    if (a == b) return a;
    for (int i = LOG; i >= 0; i--) {
        if (jump[a][i] != jump[b][i]) {
            a = jump[a][i];
            b = jump[b][i];
        }
    }
    return jump[a][0];
}

void insertNormalMin(int pos, int w) {
    auto *tree = minIntTree;
    pos += BASE;
    tree[pos] = {w, pos - BASE};
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int queryNormalMin(int posa, int posb) {
    auto *tree = minIntTree;
    posa += BASE;
    posb += BASE;
    if (posa > posb) {
        return -1;
    }
    pair<int, int> ret = min(tree[posa], tree[posb]);
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
    return ret.second;
}

void insertNormalMax(int pos, int w) {
    auto *tree = maxIntTree;
    pos += BASE;
    tree[pos] = {w, pos - BASE};
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int queryNormalMax(int posa, int posb) {
    auto *tree = maxIntTree;
    posa += BASE;
    posb += BASE;
    if (posa > posb) {
        return -1;
    }
    pair<int, int> ret = max(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = max(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = max(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret.second;
}

void insertLCA(int pos, int w) {
    auto *tree = lcaTree;
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos >= 2) {
        tree[pos] = LCA(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int queryLCA(int posa, int posb) {
    auto *tree = lcaTree;
    if (posa > posb) {
        return -1;
    }
    posa += BASE;
    posb += BASE;
    int r1 = tree[posa];
    int r2 = tree[posb];
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            r1 = LCA(r1, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            r2 = LCA(r2, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return LCA(r1, r2);
}

int main() {
    
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &jump[i][0]);
        V[jump[i][0]].push_back(i);
    }
    
    DFS(1);
    
    for (int i = 1; i <= n; i++) {
        insertNormalMin(i, inOrder[i]);
        insertNormalMax(i, inOrder[i]);
        insertLCA(i, i);
    }
    
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &a, &b);
        int lowest = queryNormalMin(a, b);
        int highest = queryNormalMax(a, b);
        int lowLcaLeft = queryLCA(a, lowest - 1);
        int lowLcaRight = queryLCA(lowest + 1, b);
        debug(lowest, lowLcaLeft, lowLcaRight);
        int lowLca = -1;
        if (lowLcaLeft > 0 && lowLcaRight > 0) {
            lowLca = LCA(lowLcaLeft, lowLcaRight);
        } else {
            lowLca = max(lowLcaLeft, lowLcaRight);
        }
        int lowDepth = lowLca == -1 ? -1 : depth[lowLca];
        debug(lowLca);
        debug(lowDepth);
    
        int highLcaLeft = queryLCA(a, highest - 1);
        int highLcaRight = queryLCA(highest + 1, b);
        
        debug(highest, highLcaLeft, highLcaRight);
        int highLca = -1;
        if (highLcaLeft > 0 && highLcaRight > 0) {
            highLca = LCA(highLcaLeft, highLcaRight);
        } else {
            highLca = max(highLcaLeft, highLcaRight);
        }
        int highDepth = highLca == -1 ? -1 : depth[highLca];
        debug(highLca);
        debug(highDepth);
        if (lowDepth > highDepth) {
            printf("%d %d\n", lowest, lowDepth);
        } else {
            printf("%d %d\n", highest, highDepth);
        }
    }
    
    return 0;
}