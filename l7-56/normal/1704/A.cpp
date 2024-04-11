#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 60;
int n, m;
char s[maxn], t[maxn];
void work() {
    scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
    for (int i = 2; i <= m; ++i)
        if (s[n - m + i] != t[i]) return printf("NO\n"), void();
    for (int i = 1; i <= n - m + 1; ++i)
        if (s[i] == t[1]) return printf("YES\n"), void();
    printf("NO\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T--) work();
	return 0;
}