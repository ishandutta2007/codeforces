#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;

const int max_n = 200008;

int main()
{
    int n, k;
    int m[150];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", m + i);
    }
    int ans = 0;
    for(int i = 0; i < k; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        int sum = 0;
        for (int j = l; j <= r; j++) sum+=m[j];
        if (sum > 0) ans += sum;
    }
    cout << ans;
    return 0;
}