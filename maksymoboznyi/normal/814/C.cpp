#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

string ss;
int n;
int ans[2001][27], s[27][1501];
int main()
{
    cin >> n;
    cin >> ss;
    ss = '#'+ss;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 26; j++)
            s[j][i] = s[j][i-1] + (ss[i] == 'a'+j-1);
    for (int i = 0; i <= 2000; i++)
        for (int j = 1; j <= 26; j++)
            ans[i][j] = 0;
    int p, a1;
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
        {
            for (int c = 1; c <= 26; c++)
            {
                p = s[c][r] - s[c][l-1];
                a1 = r - l + 1 - p;

                ans[a1][c] = max(ans[a1][c], r-l+1);
            }
        }
    for (int c = 1; c <= 26; c++)
        for (int i = 1; i <= n; i++)
            ans[i][c] = max(ans[i][c], ans[i-1][c]);
    int q;
    int x;
    char y;
    cin >> q;
    for (int u = 0; u < q; u++)
    {
        cin >> x >> y;
        cout << ans[x][y-'a'+1]<<endl;
    }
    return 0;
}