#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second

const int maxn = 2e5 + 10;
int n, pre[maxn], f[maxn];
char s[maxn];
vi e[maxn];

void dfs(int u) {
    if (f[u]) return;
    f[u] = 1;
    for (int v : e[u]) dfs(v);
}

void work() {
    map <int, int> mp;
    scanf("%d%s", &n, s + 1);
    n <<= 1;
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + (s[i] == '(') - (s[i] == ')');
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = mp.find(pre[i]);
        if (it != mp.end() && s[i] == ')')
            e[it -> sec + 1].push_back(i),
            e[i].push_back(it -> sec + 1);
        if (i < n) {
            if (s[i + 1] == '(' && s[i] == ')')
                e[i].push_back(i + 1), e[i + 1].push_back(i);
            if (s[i + 1] == '(') mp[pre[i]] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (!f[i]) dfs(i), ans++;
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) e[i].resize(0), f[i] = 0;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) work();
	return 0;
}