#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const long long M = 1e9 + 7;
const int N = 5205;

int a[N][N], b[N][N];
int n;

void parse(int g, int pos, char c) {
    int val;
    if (c <= '9')
        val = c - '0';
    else
        val = c - 'A' + 10;
    //cout << val << endl;
    for (int i = 0; i < 4; i++)
        if ((val >> i) & 1)
            a[g][pos + 3 - i] = 1;
        else
            a[g][pos + 3 - i] = 0;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + j + j + j <= n; j++)
        {
            char x;
            cin >> x;
            parse(i, (j - 1) * 4 + 1, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        for (int j = 2; j <= n; j++)
            if (a[i][j] == a[i][j - 1])
                cur++;
            else {
                //cout << cur << endl;
                ans = __gcd(ans, cur);
                cur = 1;
            }
        //cout << cur << endl;
        ans = __gcd(ans, cur);
    }
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        for (int j = 2; j <= n; j++)
            if (a[j][i] == a[j - 1][i])
                cur++;
            else {
                ans = __gcd(ans, cur);
                cur = 1;
            }
        ans = __gcd(ans, cur);
    }
    cout << ans;
    return 0;
}