#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m;
int cnt[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    int res = 1005;
    for (int i = 1; i <= n; i++)
        res = min(res, cnt[i]);
    cout << res << endl;
    return 0;
}