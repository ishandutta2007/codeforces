#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1e6 + 100;
int q, n, m, fail[maxn], trs[maxn][26];
char s[maxn];
void solve(int i) {
    for (int c = 0; c < 26; ++c)
        if (c == s[i + 1] - 'a') trs[i][c] = i + 1, fail[i + 1] = trs[fail[i]][c];
        else trs[i][c] = trs[fail[i]][c];
}

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    trs[0][s[1] - 'a'] = 1;
    for (int i = 1; i < n; ++i) solve(i);
    scanf("%d", &q);
    while (q--) {
        scanf("%s", s + n + 1);
        m = strlen(s + n + 1);
        for (int i = 0; i < m; ++i) solve(n + i);
        for (int i = 1; i <= m; ++i)
            printf("%d%c", fail[n + i], " \n"[i == m]);
    }
	return 0;
}