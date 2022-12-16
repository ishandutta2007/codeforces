#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 5e5 + 10, N = 100;
int n, f[N + 10];
char s[maxn];
int SG(int x) {
    if (x <= N) return f[x];
    return f[(x - 68) % 34 + 68];
}
void work() {
    scanf("%d%s", &n, s + 1);
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; ++i) cnt[s[i] == 'B']++;
    if (cnt[0] != cnt[1]) return printf(cnt[0] > cnt[1] ? "Alice\n" : "Bob\n"), void();
    int ans = 0;
    for (int l = 1, r; l <= n; l = r) {
        for (r = l + 1; r <= n && s[r] != s[r - 1]; ++r);
        ans ^= SG(r - l);
    }
    printf(ans ? "Alice\n" : "Bob\n");
}

int main() {
    for (int i = 1; i <= N; ++i) {
        bitset <N + 10> vis;
        for (int j = 1; j < i; ++j)
            vis[f[j - 1] ^ f[i - j - 1]] = 1;
        while (vis[f[i]]) ++f[i];
        // printf("(%d, %d)\n", i, f[i]);
    }
    int T; scanf("%d", &T);
    while (T--) work();
	return 0;
}