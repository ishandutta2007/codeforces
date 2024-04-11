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

const int N = 2e5 + 5;

long double s[N];
int x[N], y[N], id[N];
int n, k;

bool cmp(int i, int j) {
    if (x[i] != x[j]) return x[i] < x[j];
    return y[i] < y[j];
}

long double dis(int i, int j) {
    if (!i || !j) return 1e18;
    return sqrt(1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]));
}

void solve(int A, int B) {
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (1ll * (x[B] - x[A]) * (y[i] - y[A]) != 1ll * (y[B] - y[A]) * (x[i] - x[A])) {
            if (pos) return;
            pos = i;
        }
    }
    if (!pos) pos = 6 - A - B;
    long double ans = 1e18;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (i != pos) {
            id[++len] = i;
        }
    }
    sort(id + 1, id + len + 1, cmp);
    if (k == pos) {
        long double sum = dis(k, id[1]);
        for (int i = 2; i <= len; i++) sum += dis(id[i], id[i - 1]);
        ans = min(ans, sum);
        sum = dis(k, id[len]);
        for (int i = len - 1; i >= 1; i--) sum += dis(id[i], id[i + 1]);
        ans = min(ans, sum);
    } else {
        int poss = 0;
        for (int i = 1; i <= len; i++) {
            if (id[i] == k) {
                poss = i;
            }
        }
        for (int i = 1; i < len; i++) s[i] = s[i - 1] + dis(id[i], id[i + 1]);
        ans = min(ans, s[poss - 1] + dis(id[1], pos) + (poss == len ? 0 : min(dis(pos, id[poss + 1]), dis(pos, id[len])) + s[len - 1] - s[poss]));
        for (int i = poss + 1; i <= len; i++) {
            ans = min(ans, s[poss - 1] + s[i - 1] + dis(id[i], pos) + (i == len ? 0 : min(dis(pos, id[i + 1]), dis(pos, id[len])) + s[len - 1] - s[i]));
        }
        if (poss == 1) ans = min(ans, dis(id[poss], pos) + min(dis(pos, id[2]), dis(pos, id[len])) + s[len - 1] - s[1]);
        else if (poss == len) ans = min(ans, dis(id[poss], pos) + min(dis(pos, id[1]), dis(pos, id[len - 1])) + s[len - 2]);
        else ans = min(ans, dis(id[poss], pos) + min(dis(pos, id[1]), dis(pos, id[len])) + s[len - 1]);
        reverse(id + 1, id + len + 1); poss = len - poss + 1;
        for (int i = 1; i < len; i++) s[i] = s[i - 1] + dis(id[i], id[i + 1]);
        ans = min(ans, s[poss - 1] + dis(id[1], pos) + (poss == len ? 0 : min(dis(pos, id[poss + 1]), dis(pos, id[len])) + s[len - 1] - s[poss]));
        for (int i = poss + 1; i <= len; i++) {
            ans = min(ans, s[poss - 1] + s[i - 1] + dis(id[i], pos) + (i == len ? 0 : min(dis(pos, id[i + 1]), dis(pos, id[len])) + s[len - 1] - s[i]));
        }
        if (poss == 1) ans = min(ans, dis(id[poss], pos) + min(dis(pos, id[2]), dis(pos, id[len])) + s[len - 1] - s[1]);
        else if (poss == len) ans = min(ans, dis(id[poss], pos) + min(dis(pos, id[1]), dis(pos, id[len - 1])) + s[len - 2]);
        else ans = min(ans, dis(id[poss], pos) + min(dis(pos, id[1]), dis(pos, id[len])) + s[len - 1]);
    }
    printf("%.10lf\n", (double)ans);
    exit(0);
}

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
    solve(1, 2); solve(1, 3); solve(2, 3);
    return 0;
}