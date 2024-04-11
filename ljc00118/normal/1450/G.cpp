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

const int N = 20;

int f[1 << N];
char c[5005];
int id[26], l[26], r[26], cnt[26];
int n, m, a, b;

bool cmp(int i, int j) { return l[i] < l[j]; }

int main() {
    read(n); read(a); read(b); scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) {
        if (!l[c[i] - 'a']) l[c[i] - 'a'] = i;
        r[c[i] - 'a'] = i;
        ++cnt[c[i] - 'a'];
    }
    for (int i = 0; i <= 25; i++) {
        if (cnt[i]) {
            id[m] = i;
            ++m;
        }
    }
    if (m == 1) {
        print(1, ' '); putchar(id[0] + 'a'); putchar('\n');
        return 0;
    }
    sort(id, id + m, cmp);
    for (int i = 0; i < m; i++) {
        if (cnt[id[i]] * b >= (r[id[i]] - l[id[i]] + 1) * a) {
            f[1 << i] = 1;
        }
    }
    for (int i = 1; i < (1 << m); i++) {
        if ((i & (i - 1)) == 0) continue;
        int nowl = 1e9, nowr = 0, nowcnt = 0, state = 0;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                nowl = min(nowl, l[id[j]]);
                nowr = max(nowr, r[id[j]]);
                nowcnt += cnt[id[j]];
                state |= (1 << j);
                if (f[state] & f[i ^ state]) {
                    f[i] = 1;
                    break;
                }
            }
        }
        if (!f[i] && nowcnt * b >= (nowr - nowl + 1) * a) {
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    if (f[i ^ (1 << j)]) {
                        f[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    vector <char> ans;
    for (int i = 0; i < m; i++) {
        if (f[((1 << m) - 1) ^ (1 << i)]) {
            ans.push_back(id[i] + 'a');
        }
    }
    sort(ans.begin(), ans.end());
    print((int)ans.size(), ' ');
    for (auto i : ans) putchar(i), putchar(' ');
    putchar('\n');
    return 0;
}