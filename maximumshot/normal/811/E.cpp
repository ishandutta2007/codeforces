#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 10;
int const M = 1e5 + 5;

struct Node {
    int compLeft[N];
    int compRight[N];
    int tl, tr;
    int cnt;
    int cntComp;
    Node() {
        tl = tr = 0;
        cnt = 0;
        for(int i = 0;i < N;i++) {
            compLeft[i] = 0;
            compRight[i] = 0;
        }
    }
};

int n, m, q;
int a[N][M];
Node t[4 * M];
vec< int > g[100];
int used[100];
int nwcl[100];
int newColor[100];

Node merge(Node const & l, Node const & r) {
    Node res;
    res.tl = l.tl;
    res.tr = r.tr;
    int cntCompLeft = l.cntComp;
    int cntCompRight = r.cntComp;
    int cntComp = cntCompLeft + cntCompRight;
    for(int i = 0;i < cntComp;i++) {
        g[i].clear();
        used[i] = 0;
        nwcl[i] = -1;
    }
    for(int i = 0;i < n;i++) {
        if(a[i][l.tr] == a[i][r.tl]) {
            int u = l.compRight[i];
            int v = r.compLeft[i] + cntCompLeft;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int cur = 0;
    queue< int > que;
    for(int i = 0;i < cntComp;i++) {
        if(used[i]) continue;
        used[i] = 1;
        que.push(i);
        nwcl[i] = cur;
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(int to : g[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    nwcl[to] = cur;
                    que.push(to);
                }
            }
        }
        cur++;
    }

    res.cnt = l.cnt + r.cnt - cntCompLeft - cntCompRight + cur;

    for(int i = 0;i < cur;i++) {
        newColor[i] = -1;
    }

    int ptr = 0;

    for(int tmp, i = 0;i < n;i++) {
        tmp = nwcl[l.compLeft[i]];
        if(newColor[tmp] == -1) {
            newColor[tmp] = ptr++;
        }
        res.compLeft[i] = newColor[tmp];
    }

    for(int tmp, i = 0;i < n;i++) {
        tmp = nwcl[r.compRight[i] + cntCompLeft];
        if(newColor[tmp] == -1) {
            newColor[tmp] = ptr++;
        }
        res.compRight[i] = newColor[tmp];
    }

    res.cntComp = ptr;

    return res;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].cnt = 0;
        for(int i = 0;i < n;i++) {
            int j = i;
            while(j < n && a[i][tl] == a[j][tl]) j++;
            j--;
            for(int it = i;it <= j;it++) {
                t[v].compLeft[it] = t[v].compRight[it] = t[v].cnt;
            }
            t[v].cnt++;
            i = j;
        }
        t[v].tl = tl;
        t[v].tr = tr;
        t[v].cntComp = t[v].cnt;
    }else {
        int tm = (tl + tr) / 2;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

//    cout << tl << " .. " << tr << "\n";
//    cout << "cnt = " << t[v].cnt << "\n";
//    for(int i = 0;i < n;i++) {
//        cout << t[v].compLeft[i] << " " << t[v].compRight[i] << "\n";
//    }
//    cout << "\n";
}

void prepare() {
    build(1, 1, m);
}

Node query(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return t[v];
    }else {
        int tm = (tl + tr) / 2;
        if(l <= tm) {
            if(r > tm) {
                return merge(query(v << 1, tl, tm, l, r), query(v << 1 | 1, tm + 1, tr, l, r));
            }else {
                return query(v << 1, tl, tm, l, r);
            }
        }else {
            return query(v << 1 | 1, tm + 1, tr, l, r);
        }
    }
}

int query(int l, int r) {
    Node res = query(1, 1, m, l, r);
    return res.cnt;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0;i < n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    prepare();

    for(int l, r, iter = 0;iter < q;iter++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    }

    return 0;
}