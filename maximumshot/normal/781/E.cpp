#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline void Add(int & a, int b) {
    a = Sum(a, b);
}

int const N = 1e5 + 5;

struct pt {
    int x, y;
    int * ptr;
    pt() : x(0), y(0), ptr(0) { }
    pt(int x, int y, int * ptr) : x(x), y(y), ptr(ptr) { }
};

struct rec {
    int lx, rx, ly, ry;
    int id;
    rec() : lx(0), rx(0), ly(0), ry(0), id(0) { }
    rec(int lx, int rx, int ly, int ry, int id) :
        lx(lx), rx(rx), ly(ly), ry(ry), id(id) { }
};

struct segment_tree {
    int n; // 0 .. n - 1
    vector< set< pii > > tree;
    segment_tree() : n(0) { }
    segment_tree(int n) : n(n) {
        tree.resize(4 * n);
    }
    void add(int v, int tl, int tr, int l, int r, pii x, bool ins) {
        if(l <= tl && tr <= r) {
            if(ins) {
                tree[v].insert(x);
            }else {
                tree[v].erase(x);
            }
        }else {
            int tm = (tl + tr) / 2;
            if(l <= tm) add(v * 2 + 1, tl, tm, l, r, x, ins);
            if(r > tm) add(v * 2 + 2, tm + 1, tr, l, r, x, ins);
        }
    }
    void add(int l, int r, pii x, bool ins) {
        add(0, 0, n - 1, l, r, x, ins);
    }
    pii get(int v, int tl, int tr, int x) {
        pii res = tree[v].empty() ? make_pair(-1, 0) : *(--tree[v].end());
        if(tl < tr) {
            int tm = (tl + tr) / 2;
            if(x <= tm) {
                res = max(
                    res,
                    get(v * 2 + 1, tl, tm, x)
                );
            }else {
                res = max(
                    res,
                    get(v * 2 + 2, tm + 1, tr, x)
                );
            }
        }
        return res;
    }
    int get(int x) {
        return get(0, 0, n - 1, x).second;
    }
};

void solve(vector< pt > queries, vector< rec > answers) {
    // compress begin
    vector< int > crd;
    for(pt p : queries) crd.push_back(p.y);
    for(rec r : answers) {
        crd.push_back(r.ly);
        crd.push_back(r.ry);
    }
    sort(crd.begin(), crd.end());
    int sz;
    crd.resize(sz = unique(crd.begin(), crd.end()) - crd.begin());
    for(pt & p : queries) {
        p.y = lower_bound(crd.begin(), crd.end(), p.y) - crd.begin();
    }
    for(rec & r : answers) {
        r.ly = lower_bound(crd.begin(), crd.end(), r.ly) - crd.begin();
        r.ry = lower_bound(crd.begin(), crd.end(), r.ry) - crd.begin();
    }
    // compress end


    vector< rec > ins[N];
    vector< rec > era[N];
    vector< pt  > ask[N];
    segment_tree st(sz);

    for(pt & p : queries) {
        ask[p.x].push_back(p);
    }

    for(rec & r : answers) {
        ins[r.lx].push_back(r);
        era[r.rx].push_back(r);
    }

    for(int x = 0;x < N;x++) {
        for(rec& r : ins[x]) {
            st.add(r.ly, r.ry, make_pair(r.ly, r.id), 1);
        }
        for(pt& p : ask[x]) {
//            cout << st.get(p.y) << " !!\n";
            *p.ptr = st.get(p.y);
        }
        for(rec& r : era[x]) {
            st.add(r.ly, r.ry, make_pair(r.ly, r.id), 0);
        }
    }
}

int h, w, n;
pii seg[N];
int str[N];
int s[N];

void read() {
    scanf("%d %d %d", &h, &w, &n);
    for(int l, r, i = 1;i <= n;i++) {
        scanf("%d %d %d %d", &str[i], &l, &r, &s[i]);
        seg[i] = make_pair(l, r);
    }
}

pt a[N]; // up
pair< pt, pt > b[N]; // mid

vector< pt > build_points() {
    vector< pt > queries;
    for(int y = h + 1, x = 1;x <= w;x++) {
        a[x] = pt(x, y, new int(0));
        queries.push_back(a[x]);
    }
    for(int i = 1;i <= n;i++) {
        if(seg[i].first > 1) {
            b[i].first = pt(seg[i].first - 1, str[i], new int(0));
        }else {
            b[i].first = pt(seg[i].second + 1, str[i], new int(0));
        }
        if(seg[i].second < w) {
            b[i].second = pt(seg[i].second + 1, str[i], new int(0));
        }else {
            b[i].second = pt(seg[i].first - 1, str[i], new int(0));
        }
        queries.push_back(b[i].first);
        queries.push_back(b[i].second);
    }
    return queries;
}

vector< rec > build_rectangles() {
    vector< rec > answers;
    for(int i = 1;i <= n;i++) {
        answers.push_back(
            rec(seg[i].first, seg[i].second, str[i], str[i] + s[i], i)
        );
    }
    return answers;
}

void print() {
    vector< vector< char > > mat(h + 2, vector< char >(w + 2, ' '));
    for(int i = 0;i <= w + 1;i++) {
        mat[h + 1][i] = '#';
        mat[0][i] = '#';
    }
    for(int i = h;i >= 1;i--) mat[i][0] = mat[i][w + 1] = '#';
    for(int i = 1;i <= n;i++) {
        for(int j = seg[i].first;j <= seg[i].second;j++) {
            mat[ str[i] ][j] = '_';
        }
    }
    for(int i = h + 1;i >= 0;i--) {
        for(int j = 0;j <= w + 1;j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int calc() {
    vector< int > perm;
    for(int i = 1;i <= n;i++) {
        perm.push_back(i);
    }
    sort(perm.begin(), perm.end(), [&](int i, int j) {
        return str[i] < str[j];
    });
    vector< int > dp(n + 1);
    dp[0] = 1;
    for(int x : perm) {
        dp[x] = Sum( dp[*b[x].first.ptr], dp[*b[x].second.ptr] );
    }
    int res = 0;
    for(int x = 1;x <= w;x++) {
        Add(res, dp[*a[x].ptr]);
    }
    return res;
}

int fast() {
    read();
//    print();
    solve(
        build_points(),
        build_rectangles()
    );
    return calc();
}

int main() {

//    freopen("input.txt", "r", stdin);

    printf("%d\n", fast());

    return 0;
}