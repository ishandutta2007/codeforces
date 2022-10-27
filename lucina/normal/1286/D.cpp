#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353; /// delete useless stuffs
const int nax = 1e5 + 10;

void plusle (int &a, int b) {
    if ((a += b) >= mod) a -= mod;
}

int add (int a, int b) {
    return ((a += b) >= mod) ? a - mod : a;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, long long b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int inv (int a) {
    return power(a, mod - 2);
}

struct frac_t {
    int x, y;

    frac_t () {}
    frac_t (int a, int b) {
        if (b < 0) a = -a, b = -a;
    //    int g = __gcd(a, b);
    //    a /= g, b /= g;
        x = a, y = b;
    }

    bool operator < (const frac_t &other) const {
        return 1LL * x * other.y < 1LL * y * other.x;
    }

    bool operator == (const frac_t &other) const {
        return 1LL * x * other.y == 1LL * y * other.x;
    }

    int get_mod () const {
        return mul(x, inv(y));
    }
};

struct point {
    int x, v, p;
    void read() {
        scanf("%d %d %d", &x, &v, &p);
    }
};

struct node_t {
    int l, r;
    int val[2][2];
    node_t (): l(), r() {
        memset(val, 0, sizeof(val));
    }

    int get_sum () const {
        int res = 0;
        for (int i = 0 ; i < 2; ++ i)
            plusle(res, add(val[i][0], val[i][1]));
        return res;
    }
};

bool can[nax][2][2];
node_t sg[nax << 2];
node_t operator + (const node_t &lhs, const node_t &rhs) {
    node_t res;
    res.l = lhs.l, res.r = rhs.r;

    for (int x = 0 ; x < 2 ; ++ x)
    for (int y = 0 ; y < 2 ; ++ y)
    for (int i = 0 ; i < 2 ; ++ i)
    for (int j = 0 ; j < 2 ; ++ j) {
        if (can[lhs.r][i][j])
            plusle(res.val[x][y] , mul(lhs.val[x][i], rhs.val[j][y]));
    }

    return res;
}

struct event_t {
    frac_t tim;
    int pos;
    int a, b; /// config
    event_t () {}
    event_t (frac_t tim, int pos, int a, int b) : tim(tim), pos(pos), a(a), b(b) {}
    bool operator < (const event_t &other) const {
        return tim < other.tim;
    }
};
const int inv100 = inv(100);
event_t event[nax * 2];
int m = 0;
point a[nax];
int n;
vector <pair <int, int>> ans;
int prob[nax][2][2];

void build (int v, int l, int r) {
    if (l == r) {
        for (int i = 0; i < 2 ; ++ i)
        for (int j = 0 ; j < 2 ; ++ j)
            sg[v].val[i][j] = prob[l][i][j];
        sg[v].l = sg[v].r = l;
    } else {
        int mid = l + r >> 1;
        build(v << 1, l, mid);
        build(v << 1 | 1, mid + 1, r);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

void rebuild (int v, int x, int y, int pos) {
    if (x == y) {
        return ;
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) rebuild(v << 1, x, mid, pos);
        else rebuild(v << 1 | 1, mid + 1, y, pos);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i)
        a[i].read();

    if (n == 1) return !printf("0");

    for (int i = 1 ; i < n ; ++ i) {
        int dist = a[i + 1].x - a[i].x;
        event[++ m] = event_t(frac_t(dist, a[i + 1].v + a[i].v), i, 1, 0);
        if (a[i].v > a[i + 1].v)
            event[++ m] = event_t(frac_t(dist, a[i].v - a[i + 1].v), i, 1, 1);
        if (a[i].v < a[i + 1].v)
            event[++ m] = event_t(frac_t(dist, a[i + 1].v - a[i].v), i, 0, 0);
    }
    sort(event + 1, event + 1 + m);
    for (int i = 1 ; i < n ; ++ i)
    for (int x = 0 ; x < 2 ; ++ x)
    for (int y = 0 ; y < 2 ; ++ y)
        can[i][x][y] = true;

    for (int i = 1 ; i <= n ; ++ i) {
        prob[i][1][1] = 1LL * a[i].p * inv100 % mod;
        prob[i][0][0] = 1LL * (100 - a[i].p) * inv100 % mod;
    }

    build(1, 1, n);
    ans.emplace_back(0, 1);

    for (int i = 1 ; i <= m ; ++ i) {
        int j = i;
        while (j <= m && event[j].tim == event[i].tim) ++ j;
        for (int k = i ; k < j ; ++ k) {
            can[event[k].pos][event[k].a][event[k].b] = false;
            rebuild(1, 1, n, event[k].pos);
        }
        ans.emplace_back(event[i].tim.get_mod(), sg[1].get_sum());

        i = j - 1;
    }

    int answer = 0;
    for (int i = 1 ; i < int(ans.size()) ; ++ i) {
        plusle(answer, mul(ans[i].first, sub(ans[i - 1].second, ans[i].second)));
    }

    printf("%d\n", answer);
}