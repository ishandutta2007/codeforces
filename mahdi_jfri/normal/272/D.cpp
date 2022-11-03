#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
pair<ll , ll> a[maxn];
ll m , ans = 1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i + n].first;
        a[i + n].second = i;
    }
    cin >> m;
    sort(a , a + 2 * n);
    for(int i = 0; i < 2 * n; i++)
    {
        ll j = i , t = 0;
        while(a[i].first == a[i + 1].first)
            i++;
        for(int k = j + 1; k <= i; k++)
            if(a[k].second == a[k - 1].second)
                t++;
        for(int k = j; k <= i; k++)
        {
            ll z = k - j + 1;
            while(z % 2 == 0 && t)
            {
                z /= 2;
                t--;
            }
            ans *= z;
            ans %= m;
        }
    }
    cout << ans << endl;
}