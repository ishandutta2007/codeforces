/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll n, k, ans, cnt[100005], prime[100005] = {0, 1}, isprime[100005];
vector<int> v;

ll fastpow(ll b, ll p)
{
    ll a = 1;
    for (int i = 1; i <= p; i++)
    {
        a *= b;
        if (a > 1e10)
            a = 0;
    }
    return a;
}

signed main()
{
    //fast;
    cin >> n >> k;
    for (int i = 1; i <= 100000; i++)
        isprime[i] = prime[i] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        if (isprime[i])
        {
            for (int j = i; j <= 100000; j += i)
            {
                isprime[j] = 0;
                if (prime[j] * i <= 10000000)
                    prime[j] *= i;
                else
                    prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= 100000; i++)
    {
        if (fastpow(prime[i], k) % i == 0)
            prime[i] = fastpow(prime[i], k) / i;
        else
            prime[i] = 0;
    }
    for (int i = 2; i <= 100000; i++)
        if(prime[i] > 100000)
            prime[i] = 0;
            
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 2; pow(i, k) <= 1e5; i++)
    {
        int p = fastpow(i, k);
        for (int &j : v)
            while (j % p == 0)
                j /= p;
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int i : v)
        cnt[i]++;
    for (int i : v)
    {
        cnt[i]--;
        ans += cnt[prime[i]];
        cnt[i]++;
    }

    cout << ans / 2 << '\n';
}