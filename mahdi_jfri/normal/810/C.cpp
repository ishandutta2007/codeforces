#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;
const ll mod = 1e9 + 7;
ll sum[maxn] , x[maxn] , k , res;
int main()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    sort(x , x + n);
    sum[1] = x[1] - x[0];
    res = sum[1];
    k = 3;
    for(int i = 2; i < n; i++)
    {
        sum[i] = sum[i - 1] * 2 + ((x[i] - x[i - 1]) * (k)) % mod;
        sum[i] %= mod;
        k += 1;
        k *= 2;
        k -= 1;
        k = (k + mod) % mod;
        res += sum[i];
        res %= mod;
    }
    cout << max(res , 0LL);
}