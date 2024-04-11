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
int n;
int a[maxn];
int b[2][maxn];
int cnt[2];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            b[i & 1][i >> 1] = a[i];
            ++cnt[i & 1];
        }
        sort(b[0], b[0] + cnt[0]);
        sort(b[1], b[1] + cnt[1]);
        int last = b[0][0];
        bool flag = true;
        for (int i = 1; i < n; ++i) {
            int cur = b[i & 1][i >> 1];
            if (last > cur) flag = false;
            last = cur;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}