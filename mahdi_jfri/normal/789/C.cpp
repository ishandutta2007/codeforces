#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll a[maxn] , b[maxn];
ll tmp , ans;
int main()
{
    ll n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i)
            b[i - 1] = abs(a[i - 1] - a[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        ll u = b[i];
        ans = max(ans, tmp);
        if (i & 1)
            u *= -1;
        tmp += u;
        ans = max(ans, tmp);
        tmp = max(tmp , 0LL);
    }
    tmp = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ll u = b[i];
        ans = max(ans, tmp);
        if (i % 2 == 0)
            u *= -1;
        tmp += u;
        ans = max(ans, tmp);
        tmp = max(tmp , 0LL);
    }
    cout << ans;
    return 0;
}