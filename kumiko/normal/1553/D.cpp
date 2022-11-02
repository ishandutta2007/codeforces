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

const int maxn = 100005;
int T;
char s[maxn], t[maxn];
int n, m;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%s%s", s + 1, t + 1);
        n = strlen(s + 1);
        m = strlen(t + 1);
        int i = n, j = m;
        for (; j; --j) {
            while (i > 0 && s[i] != t[j]) i -= 2;
            if (i <= 0) break;
            --i;
        }
        if (j > 0)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}