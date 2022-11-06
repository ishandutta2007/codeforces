#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5+5;
ll n, k, a[N], x;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> x;
    for (int i =1; i <= n; i++)
        cin >> a[i];
    int j = n;
    while (j > 0 && k > 0)
    {
        k--;
        a[j] = x;
        j--;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];
    cout << sum;
    return 0;
}