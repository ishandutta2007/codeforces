#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e6 + 5; 

int n, m, ans;

vector<char> g[N];
vector<int> s[N], c[N];

char str[N];

int sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

bool inline get(int x, int y, int k) {
    if (x - k < 1 || x + k > n || y - k < 1 || y + k > m) return 0;
    return !sum(x - k, y - k, x + k, y + k);
}

bool inline check(int x) {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) c[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (get(i, j, x)) {
                c[i - x][j - x]++;
                c[i + x + 1][j - x]--;
                c[i - x][j + x + 1]--;
                c[i + x + 1][j + x + 1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
            char t = c[i][j] ? 'X' : '.';
            if (t != g[i][j]) return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &m); ans = 2e9;
    s[0].resize(m + 1);
    for (int i = 0; i <= n + 1; i++) c[i].resize(m + 2);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        g[i].resize(m + 1);
        s[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            g[i][j] = str[j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (g[i][j] == '.');
        }
    }

    int l = 0, r = min(n, m);
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;   
    }
    printf("%d\n", r);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            putchar(get(i, j, r) ? 'X' : '.');
        }
        puts("");
    }
    return 0;
}