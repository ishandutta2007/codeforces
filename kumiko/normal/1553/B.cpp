#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 1005;
int T;
char s[maxn], t[maxn];

void solve() {
    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != t[j]) break;
            if (m - j - 1 <= i + j) {
                bool flag = 1;
                for (int k = j + 1, ki = i + j - 1; k < m && flag; ++k, --ki) {
                    flag &= s[ki] == t[k];
                }
                if (flag) {
                    puts("YES");
                    return;
                }
            }
        }
    }
    puts("NO");
}

int main() {
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}