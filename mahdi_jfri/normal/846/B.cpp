#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll t[maxn] , s , ans;
int main()
{
    int n , k , M;
    cin >> n >> k >> M;
    for(int i = 0; i < k; i++)
        cin >> t[i] , s += t[i];
    sort(t , t + k);
    for(int i = 0; i <= n; i++)
    {
        if(s * i > M)
            break;
        ll x = M - i * s , res = i * (k + 1) , new_n = n - i;
        for(int j = 0; j < k && x > 0; j++)
        {
            res += min(x / t[j] , new_n);
            x -= min(x / t[j] , new_n) * t[j];
        }
        ans = max(ans , res);
    }
    cout << ans;
}