#include <bits/stdc++.h>
#include <Windows.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 1e6 + 5;

vector <int> vec[40];
vector <ll> ss[40];
char c[N];
int a[N], pos[N], seq[N];
int n, b, p, m, len; ll ans;

// >= x
int count(int id, int x) {
    return vec[id].end() - lower_bound(vec[id].begin(), vec[id].end(), x);
}

bool cmp(int i, int j) {
    if (a[i] != a[j]) return a[i] < a[j];
    return i < j;
}

int vis[N];
void dfs1(int u) {
    if (u > len) {
        ll now = b, all = 1;
        for (int i = 1; i <= len; i++) {
            if (vis[pos[i]]) {
                now -= m;
            }
            all *= a[pos[i]];
        }
        if (now < 0) return;
        // fprintf(stderr, "now = %lld\n", now);
        auto calc = [&](ll x) {
            ll sum = 1;
            int cnt = 0; ll ret = 0;
            for (int i = 1; i <= len + 1; i++) {
                // if (x == 1) fprintf(stderr, "i = %d, sum = %lld\n", i, sum);
                if (sum == 1 && x != 0) {
                    if (!vis[pos[i]]) sum *= a[pos[i]];
                    continue;
                }
                ll tmp = (sum - 1) * (all / sum);
                ll low = x == 0 ? 0 : (x - 1) / tmp + 1;
                // if (x == 1) fprintf(stderr, "i = %d, low = %lld\n", i, low);
                if (low <= 2e9) {
                    int ncnt = count(i, low);
                    cnt += ncnt;
                    ret += ss[i][ncnt] * tmp;
                }
                if (i == len + 1) break;
                // if (x == 1) fprintf(stderr, "pos[i] = %d, a[pos[i]] = %d, sum = %lld\n", pos[i], a[pos[i]], sum);
                if (!vis[pos[i]]) sum *= a[pos[i]];
            }
            return make_pair(cnt, ret);
        };
        // pair <int, ll> qwq = calc(1);
        // cout << qwq.first << ' ' << qwq.second << endl;
        int las = min((ll)n - len, now / p);
        ll l = 0, r = 4e18, res = 4e18;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (calc(mid).first >= las) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        ll nowans = all, sum = all;
        for (int i = 1; i <= len + 1; i++) {
            nowans += ss[i][(int)vec[i].size()] * sum;
            if (i == len + 1) continue;
            if (!vis[pos[i]]) sum /= a[pos[i]];
        }
        pair <int, ll> tmp = calc(res + 1);
        nowans += tmp.second;
        nowans += (las - tmp.first) * res;
        ans = max(ans, nowans);
        return;
    }
    int l = u, r = u;
    while (r < len && a[seq[r + 1]] == a[seq[l]]) ++r;
    dfs1(r + 1);
    for (int i = l; i <= r; i++) {
        vis[seq[i]] = 1; dfs1(r + 1);
    }
    for (int i = l; i <= r; i++) vis[seq[i]] = 0;
}

int main() {
    read(n); read(b); read(p); read(m);
    for (int i = 1; i <= n; i++) {
        c[i] = getchar();
        while (c[i] != '+' && c[i] != '*') c[i] = getchar();
        read(a[i]);
        if (c[i] == '*' && a[i] == 1) {
            --i; --n;
            continue;
        }
        if (c[i] == '*') pos[++len] = i;
    }
    for (int i = 1; i <= len; i++) {
        for (int j = pos[i - 1] + 1; j < pos[i]; j++) vec[i].push_back(a[j]);
    }
    for (int i = pos[len] + 1; i <= n; i++) vec[len + 1].push_back(a[i]);
    for (int i = 1; i <= len + 1; i++) {
        sort(vec[i].begin(), vec[i].end());
        ss[i].resize(vec[i].size() + 1);
        for (int j = 1; j <= (int)vec[i].size(); j++) ss[i][j] = ss[i][j - 1] + vec[i][(int)vec[i].size() - j];
    }
    for (int i = 1; i <= len + 1; i++) seq[i] = pos[i];
    sort(seq + 1, seq + len + 1, cmp);
    dfs1(1);
    print(ans, '\n');
    return 0;
}