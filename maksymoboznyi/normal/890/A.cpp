#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 1e6+10;
int a[10];
signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= 6; i++)
        for (int j = i+1; j <= 6; j++)
            for (int k = j + 1; k <= 6; k++)
                if (i != j && j != k && k != i && a[i] + a[j] + a[k] == sum - a[i] - a[j] - a[k])
                {
                    cout << "YES";
                    return 0;
                }
    cout << "NO";
    return 0;
}