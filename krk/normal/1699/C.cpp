#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int T;
int n;
int me[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            me[a] = i;
        }
        int l = me[0], r = me[0], sz = 0;
        int res = 1;
        for (int i = 1; i < n; i++)
            if (me[i] < l) { sz += l - me[i] - 1; l = me[i]; }
            else if (r < me[i]) { sz += me[i] - r - 1; r = me[i]; }
            else { res = ll(res) * sz % mod; sz--; }
        printf("%d\n", res);
    }
    return 0;
}