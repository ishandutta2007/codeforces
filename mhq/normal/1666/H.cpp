#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll n, d, h;
ll ans;

vector<pll> flex(vector<pll> v)
{
    vector<pll> res;
    for (auto x : v)
    {
        res.pb(x);
        while (res.size() >= 2)
        {
            pll a = res[res.size() - 2];
            pll b = res[res.size() - 1];
            // if(a.f / a.s < b.f / b.s){
            if (a.f * b.s < b.f * a.s)
            {
                ans += a.s * b.f;
                res.pop_back();
                res.pop_back();
                res.pb({a.f + b.f, a.s + b.s});
            }
            else
                break;
        }
    }
    return res;
}
vector<pll> build(ll x)
{
    vector<pll> res;

    {
        ll hh = h / __gcd(h, d);
        hh = h;
        ll cnt = x / (1ll * d * hh);
        if (cnt > 0)
        {
            x -= cnt * d * hh;
            // ll value = (hh - 1) * (d - __gcd(d, hh)) / (2 * __gcd(d, hh));
            ll value = (1ll * d * hh - d - hh + __gcd(d, hh)) / 2;
            value = 1ll * d * (hh - 1) - value;
            ans += value * cnt;
            ans += cnt * (cnt - 1) / 2 * hh * d;
            res.pb({cnt * d, cnt * hh});
        }
    }

    ll rem = 0;
    {
        ll dd = d % h;

        if (dd == 0)
        {
            ll cnt = x / d;

            if (cnt > 0)
            {
                x -= d * cnt;

                ans += cnt * (cnt - 1) / 2 * (d / h);

                rem += cnt * d;

                res.pb({rem / h, cnt});
                rem %= h;
            }
        }
        else
        {
            while (true)
            {
                ll need = (h - rem + dd - 1) / dd;
                if (need * d > x)
                    break;
                x -= need * d;

                rem += need * d;

                ans += need - 1;
                ans += need * (need - 1) / 2 * (d / h);

                res.pb({rem / h, need});
                rem %= h;
            }

            ll cnt = x / d;
            if (cnt > 0)
            {
                x -= d * cnt;

                ans += cnt * (cnt - 1) / 2 * (d / h);

                rem += cnt * d;

                res.pb({rem / h, cnt});
                rem %= h;
            }
        }
    }


    {
        while (x >= d)
        {
            rem += d;
            x -= d;
            res.pb({rem / h, 1});
            rem %= h;
        }

        if (x > 0)
        {
            res.pb({(x + h - 1) / h, 1});
        }
    }
    res = flex(res);
    return res;
}

void solve()
{
    scanf("%lld%lld%lld", &n, &d, &h);
    ans = 0;

    vector<vector<pll>> a;
    for (int i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld", &x);
        a.pb(build(x * h));
    }

    vector<pll> b;
    for (auto x : a)
        for (auto y : x)
            b.pb(y);
    sort(b.begin(), b.end(), [](pll x, pll y)
         { return x.f * y.s > y.f * x.s; });
    ll s = 0;
    for (auto x : b)
    {
        ans += s * x.f;
        s += x.s;
    }
    printf("%lld\n", ans + 1);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}