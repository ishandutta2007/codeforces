#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int md = 1e9 + 7, inv2 = (md + 1) / 2;
const ll mod = 1ll * md * (md - 1);

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct atom {
    int x, y;
    atom (int k1 = 0, int k2 = 0) : x(k1), y(k2) {}
};

atom operator + (const atom a, const atom b) {
    return atom(add(mul(a.x, b.y), b.x), mul(a.y, b.y));
}

atom fpow(atom x, ll y) {
    atom ans = atom(0, 1);
    while (y) {
        if (y & 1) ans = ans + x;
        y >>= 1; x = x + x;
    }
    return ans;
}

const int N = 1e5 + 5;

atom val[N], tmp[N];
vector <char> str[N];
ll st[N];
char c[N];
int n, top, tot, stot;

inline int fpow(int x, int y, int md) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1ll * ans * x % md;
        y >>= 1; x = 1ll * x * x % md;
    }
    return ans;
}

atom calc(int l, int r, int n1, int n2, int len) {
    if (len == 1) {
        atom ans = atom(0, 1);
        for (int i = l; i <= r; i++) ans = ans + atom(i, 10);
        return ans;
    }
    int x = fpow(10, len), ans1 = 0, ans2 = fpow(x, n2);
    if (x == 1) ans1 = mul(sub(l, 1), n1);
    else ans1 = mul(sub(l, 1), mul(sub(fpow(x, n2), 1), fpow(x - 1, md - 2)));
    int invx = fpow(x, md - 2);
    if (x == 1) ans1 = add(ans1, mul(mul(n1, add(n1, 1)), inv2));
    else {
        int res = 0;
        res = add(res, mul(mul(n1, fpow(invx, n2 + 1)), fpow(invx - 1, md - 2)));
        res = sub(res, mul(sub(fpow(invx, n2 + 1), invx), fpow(mul(invx - 1, invx - 1), md - 2)));
        ans1 = add(ans1, mul(res, fpow(x, n2)));
    }
    return atom(ans1, ans2);
}

int main() {
    for (int i = 1, l = 0, r = 9; i <= 100000; i++) {
        int n1 = 9ll * fpow(10, i - 1) % md, n2 = 9ll * fpow(10, i - 1, md - 1) % (md - 1);
        val[i] = calc(l, r, n1, n2, i);
        l = add(r, 1); r = sub(mul(l, 10), 1);
    }
    scanf("%s", c + 1); n = strlen(c + 1);
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;
        if (c[l] == '(') {
            st[++top] = -1;
            continue;
        }
        if (c[l] == '+') {
            st[++top] = -2;
            continue;
        }
        if (c[l] == '-') {
            st[++top] = -3;
            continue;
        }
        if (c[l] == ')') {
            atom ans = atom(0, 1);
            while (st[top] != -1) {
                if (st[top] != -2) ans = tmp[st[top]] + ans;
                --top;
            }
            --top;
            ans = fpow(ans, st[top]);
            st[top] = ++tot;
            tmp[tot] = ans;
            continue;
        }
        while (r < n && c[r + 1] >= '0' && c[r + 1] <= '9') ++r;
        if (st[top] == -3) {
            --top;
            int id = st[top];
            int len1 = (int)str[id].size();
            int len2 = r - l + 1;
            if (len1 == len2) {
                int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
                for (int i = 0; i < (int)str[id].size(); i++) {
                    l1 = (10ll * l1 + str[id][i] - '0') % md;
                    l2 = (10ll * l2 + str[id][i] - '0') % (md - 1);
                }
                for (int i = l; i <= r; i++) {
                    r1 = (10ll * r1 + c[i] - '0') % md;
                    r2 = (10ll * r2 + c[i] - '0') % (md - 1);
                }
                st[top] = ++tot;
                tmp[tot] = calc(l1, r1, (r1 - l1 + 1 + md) % md, (r2 - l2 + md) % (md - 1), len1);
            } else {
                int l1 = 0, l2 = 0, r1 = fpow(10, len1) - 1, r2 = (fpow(10, len1, md - 1) + md - 2) % (md - 1);
                for (int i = 0; i < (int)str[id].size(); i++) {
                    l1 = (10ll * l1 + str[id][i] - '0') % md;
                    l2 = (10ll * l2 + str[id][i] - '0') % (md - 1);
                }
                atom ans = calc(l1, r1, (r1 - l1 + 1 + md) % md, (r2 - l2 + md) % (md - 1), len1);
                for (int i = len1 + 1; i <= len2 - 1; i++) ans = ans + val[i];
                l1 = fpow(10, len2 - 1); l2 = fpow(10, len2 - 1, md - 1); r1 = 0; r2 = 0;
                for (int i = l; i <= r; i++) {
                    r1 = (10ll * r1 + c[i] - '0') % md;
                    r2 = (10ll * r2 + c[i] - '0') % (md - 1);
                }
                // fprintf(stderr, "l1 = %d, l2 = %d, r1 = %d, r2 = %d\n", l1, l2, r1, r2);
                // fprintf(stderr, "ans.x = %d, ans.y = %d\n", ans.x, ans.y);
                ans = ans + calc(l1, r1, (r1 - l1 + 1 + md) % md, (r2 - l2 + md) % (md - 1), len2);
                st[top] = ++tot;
                tmp[tot] = ans;
            }
            continue;
        }
        if (r < n && c[r + 1] == '-') {
            ++stot;
            for (int i = l; i <= r; i++) str[stot].push_back(c[i]);
            st[++top] = stot;
            continue;
        }
        if (r < n && c[r + 1] == '(') {
            ll ans = 0;
            for (int i = l; i <= r; i++) ans = (10ull * ans + c[i] - '0') % mod;
            st[++top] = ans;
            continue;
        }
        atom ans = atom(0, 1);
        for (int i = l; i <= r; i++) ans = ans + atom(c[i] - '0', 10);
        st[++top] = ++tot;
        tmp[tot] = ans;
    }
    atom ans = tmp[st[1]];
    for (int i = 3; i <= top; i += 2) ans = ans + tmp[st[i]];
    print(ans.x, '\n');
    return 0;
}