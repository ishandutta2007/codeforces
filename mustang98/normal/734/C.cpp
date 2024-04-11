#include <bits/stdc++.h>

#define F first
#define S second
#define prev privet1

using namespace std;
typedef long long ll;

const int max_n = 300009;


pair<ll, ll> z1[max_n];
ll z2[max_n], z2p[max_n];
ll n = 0, m, k, x, s;

//   ( ,     )  ,    <= sum
ll bp(ll sum)
{
    ll* a = upper_bound(z2p, z2p + k, sum);
    if (a == z2p) return 0;
    else return *(z2 + (a - z2p) - 1);
    /*int l = 0, r = k - 1;
    if (z2[l].S > sum) return 0;
    if (z2[r].S <= sum) return z2[k - 1].F;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (z2[mid].S <= sum)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return z2[l].F;*/
}

int main()
{
    cin >> n >> m >> k;
    cin >> x >> s;
    for (int i = 0; i < m; i++)
    {
        scanf("%I64d", &z1[i].F);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%I64d", &z1[i].S);
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%I64d", &z2[i]);
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%I64d", &z2p[i]);
    }

    ll ANS = 4e18;
   // cout << z1[0].S<<endl;
    for (int i = 0; i < m; i++)
    {
        ll cura = z1[i].F;
        ll curs = s - z1[i].S; //     
        if (curs < 0) continue;
        ll kolmgn = bp(curs);
        ll ans;
        ll n1 = n - kolmgn;
        if (n1 <= 0)
        {
            ans = 0;
        }
        else
        {
            ans = n1 * cura;
        }
        ANS = min(ANS, ans);
       // cout << i << ' '<< ans << endl;
    }
    ll kolmgn = bp(s);
    ll ans;
    ll n1 = n - kolmgn;
    if (n1 <= 0)
    {
        ans = 0;
    }
    else
    {
        ans = n1 * x;
    }
    ANS = min(ANS, ans);
    cout << ANS;

    return 0;
}