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

const int N = 2050;

ll maxlen[5];
int dp[N][5];
int n = 2045;

int query(vector <ll> vec) {
    print((int)vec.size(), ' ');
    for (auto i : vec) print(i, ' ');
    putchar('\n');
    fflush(stdout);
    int ans; read(ans);
    if (ans == -2) assert(0);
    if (ans == -1) exit(0);
    return ans;
}

vector <ll> getvec(int l, int r, int i) {
    vector <ll> res;
    int now = dp[l][i - 1];
    for (int _ = 1; _ <= l && now < r; _++) {
        ++now;
        res.push_back(now);
        if (now == r) break;
        now = dp[now + 1][i - 1];
    }
    return res;
}

void bigsolve(ll l, ll r, int cnt) {
    if (cnt == 1) {
        vector <ll> tem;
        for (ll i = l; i <= r; i++) tem.push_back(i);
        query(tem);
        return;
    }
    vector <ll> tem;
    ll now = l - 1;
    for (int i = 1; i <= 10000; i++) {
        now += maxlen[cnt - 1] + 1;
        tem.push_back(now);
    }
    int pos = query(tem);
    if (pos == 0) bigsolve(l, tem[0] - 1, cnt - 1);
    else if (pos == 10000) bigsolve(tem[9999] + 1, r, cnt - 1);
    else bigsolve(tem[pos - 1] + 1, tem[pos] - 1, cnt - 1);
}

void smallsolve(int l, int r, int cnt) {
    if (cnt == 1) {
        vector <ll> tem;
        for (int i = l; i <= r; i++) tem.push_back(i);
        query(tem);
        return;
    }
    vector <ll> tem = getvec(l, r, cnt);
    int pos = query(tem);
    if (pos == 0) smallsolve(l, tem[0] - 1, cnt - 1);
    else if (pos == (int)tem.size()) smallsolve(tem[(int)tem.size() - 1] + 1, r, cnt - 1);
    else smallsolve(tem[pos - 1] + 1, tem[pos] - 1, cnt - 1);
}

int main() {
    for (int l = n; l >= 1; l--) {
        dp[l][1] = l * 2 - 1;
        for (int i = 2; i <= 4; i++) {
            int now = dp[l][i - 1];
            for (int _ = 1; _ <= l && now < n; _++) {
                ++now;
                if (now == n) break;
                now = dp[now + 1][i - 1];
            }
            dp[l][i] = now;
        }
    }
    ll M = 10004205361450474;
    maxlen[1] = 10000;
    for (int i = 2; i <= 4; i++) maxlen[i] = maxlen[i - 1] * 10001 + 10000;
    vector <ll> tem(1, M - maxlen[4]);
    int res = query(tem);
    if (res == 1) {
        bigsolve(M - maxlen[4] + 1, M, 4);
        return 0;
    }
    tem[0] = 2046;
    res = query(tem);
    if (res == 0) {
        smallsolve(1, 2045, 3);
        return 0;
    }
    ll l = 2047, r = M - maxlen[4] - 1, len = maxlen[2] * 2047 + 2046;
    tem.clear();
    tem.push_back(r - len); ll now = r - len;
    for (int i = 1; i <= 2046; i++) {
        now += maxlen[2] + 1;
        tem.push_back(now);
    }
    res = query(tem);
    if (res == 0) r = tem[0] - 1;
    else if (res == 2047) l = tem[2046] + 1;
    else l = tem[res - 1] + 1, r = tem[res] - 1;
    if (res >= 1) {
        bigsolve(l, r, 2);
        return 0;
    }
    tem.clear();
    while (r - l + 1 > 10000) {
        ll pos = l + min(l, 10000ll);
        tem.push_back(pos);
        l = pos + 1;
    }
    res = query(tem);
    if (res == 0) r = tem[0] - 1;
    else if (res == 2047) l = tem[2046] + 1;
    else l = tem[res - 1] + 1, r = tem[res] - 1;
    tem.clear();
    for (ll i = l; i <= r; i++) tem.push_back(i);
    query(tem);
    return 0;
}