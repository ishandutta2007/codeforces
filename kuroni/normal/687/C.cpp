#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, k, chk[505][505], cur, i, j;
long long ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    memset(chk, 0, sizeof(chk)); 
    chk[0][0] = 1;
    while (n--)
    {
        cin >> cur;
        for (i = k - cur; i >= 0; i--)
            for (j = k; j >= 0; j--)
                if (chk[i][j])
                {
                    chk[i + cur][j] = 1;
                    if (j + cur <= k)
                        chk[i + cur][j + cur] = 1;
                }
    }
    for (i = 0; i <= k; i++)
        ans += chk[k][i];
    cout << ans << '\n';
    for (i = 0; i <= k; i++)
        if (chk[k][i]) 
            cout << i << " ";
}