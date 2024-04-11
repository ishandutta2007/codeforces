#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n;
vector<int> g;
inline void Factor(int n) {
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        g.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) g.push_back(n);
}
int tot, px[N], py[N];
inline void Do(int num, int val) {
    ++tot;
    px[tot] = num;
    py[tot] = n / val;
}
int f[N];
pii fr[N];
inline void Spfa(int n) {
    static priority_queue<pii, vector<pii>, greater<pii> > q;
    for (int i = 0; i < n; ++i) f[i] = 2e9;
    f[0] = 0;
    q.push(pii(f[0], 0));
    while (!q.empty()) {
        pii u = q.top(); q.pop();
        int x = u.second;
        if (u.second > f[x]) continue;
        for (int i = 0; i < (int)g.size(); ++i) {
            int nx = (x + g[i]) % n;
            if (f[x] + g[i] < f[nx]) {
                f[nx] = f[x] + g[i];
                fr[nx] = pii(x, g[i]);
                q.push(pii(f[nx], nx));
            }
        }
    }
    if (f[n - 1] > ::n - 1) exit(puts("NO") * 0);
    int rm = ::n - 1;
    for (int i = n - 1; i; i = fr[i].first) {
        Do(1, fr[i].second);
        rm -= fr[i].second;
    }
    if (rm) Do(rm / n, n);
}
int main() {
    scanf("%d", &n);
    Factor(n);
    if (g.size() == 1) return puts("NO"), 0;
    Spfa(g[0]);
    puts("YES");
    printf("%d\n", tot);
    for (int i = 1; i <= tot; ++i) printf("%d %d\n", px[i], py[i]);
    return 0;
}