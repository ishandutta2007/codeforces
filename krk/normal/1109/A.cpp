#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 1 << 20;

int n;
int a[Maxn];
int cnt[Maxm][2];
ll res;

int main()
{
    cnt[0][0]++;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];
        res += cnt[a[i]][i % 2]++;
    }
    cout << res << endl;
    return 0;
}