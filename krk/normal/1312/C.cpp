#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 50;

int T;
int n, k;
ll a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        map <int, int> M;
        for (int i = 0; i < n; i++) {
            scanf("%I64d", &a[i]);
            int cnt = 0;
            while (a[i] > 0) {
                M[cnt] += a[i] % k;
                a[i] /= k;
                cnt++;
            }
        }
        bool ok = true;
        for (map <int, int>::iterator it = M.begin(); it != M.end() && ok; it++)
            ok = it->second <= 1;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}