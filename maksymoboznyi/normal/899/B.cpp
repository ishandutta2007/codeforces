#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define M 1000000007;
using namespace std;
const int N = 2e5+6;
const int a1[8*12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,   31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int s = 0; s + n < 8*12; s++)
    {
        bool r = 1;
        for (int j = 1; j <= n; j++)
            if (a[j] != a1[s+j])
            {
                r = 0;
                break;
            }
        if (r)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}