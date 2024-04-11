#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;

const int max_n = 200008;

int main()
{
    int l, r, n, m;
    cin >> n >> m;
    int ans = 1e9;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        l--;
        r--;
        ans = min(ans, r - l + 1);
    }
    cout << ans << "\n";
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cout << cur % ans << ' ';
        cur++;
    }
    return 0;
}