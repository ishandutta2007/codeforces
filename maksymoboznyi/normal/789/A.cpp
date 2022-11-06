#include <bits/stdc++.h>

using namespace std;

int n, k;
int w[100005];
int main()
{
    cin >> n >> k;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        ans += (w[i]-1) / k + 1;
    }
    cout << (ans - 1) / 2 + 1;
    return 0;
}