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

const int N = 1e4 + 5;

int n;

int inline ask(int x) {
    printf("? %d\n", x);
    fflush(stdout);
    int t; read(t);
    return t;
}

set<int> s;

bool st[N];

int ans[N];
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        s.clear();
        for (int i = 1; i <= n; i++) st[i] = ans[i] = 0, s.insert(i);
        while (s.size()) {
            int u = *s.begin();
            while (ask(u) != u);
            int x = u;
            while (1) {
                int t = ask(u);
                st[x] = 1;
                ans[x] = t;
                s.erase(t);
                x = t;
                if (x == u) break;
            }
        }
        printf("!");
        for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
        puts("");
        fflush(stdout);
    }
    return 0;
}