// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, c[N];

char s[N], t[N], g[N];

vector<int> p[26];

void inline add(int x, int k) {
    for (; x <= n; x += x & -x) c[x] += k;
}
int inline ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += c[x];
    return res;
}
 
bool inline chk() {
    for (int i = 1; i <= n; i++) g[i] = s[i];
    sort(g + 1, g + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (g[i] != t[i]) {
            if (g[i] < t[i]) return 1;
            return 0;
        }
    }
    return 0;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        scanf("%s%s", s + 1, t + 1);
        if (!chk()) {
            puts("-1");
            continue;
        }
        for (int i = n; i; i--) p[s[i] - 'a'].pb(i);
        for (int i = 1; i <= n; i++) add(i, 1);
        LL ans = 9e18, s = 0;
        for (int i = 1; i <= n; i++) {
            int c = t[i] - 'a';
            for (int j = 0; j < c; j++) {
                if (p[j].size()) {
                   // cout << s << " " << i << " " << (char)(j + 'a') << " " << ask(p[j].back()) << " aaa" << p[j].back() << endl;
                    chkMin(ans, s + ask(p[j].back()) - 1);
                }
            }
            if (p[c].size()) {
                int u = p[c].back();
                s += ask(u) - 1;
                //cout << u << " " << ask(u) << " wnmdnmd\n";
                add(u, -1);
                p[c].pop_back();
            } else break;
            //cout << s << "aaa??\n"; 
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) c[i] = 0;
        
        for (int i = 0; i < 26; i++) p[i].clear();
    }
    return 0;
}