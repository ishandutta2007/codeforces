#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

struct Friend
{
    int h, w, id;
};

bool comp(Friend f1, Friend f2)
{
    return make_tuple(f1.h, f1.w, f1.id) < make_tuple(f2.h, f2.w, f2.id);
}

Friend standard(Friend f)
{
    f.w = 0;
    f.id = 0;
    return f;
}

Friend reverse(Friend f)
{
    swap(f.h, f.w);
    f.w = 0;
    f.id = 0;
    return f;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        vector<Friend> v, minw;
        vector<int> r(200005, -1);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int w, h;
            cin >> h >> w;
            v.emplace_back(Friend{h, w, i + 1});
        }
        sort(v.begin(), v.end(), comp);
        minw.emplace_back(v[0]);
        for (int i = 1; i < n; i++)
            if (minw[i - 1].w <= v[i].w)
                minw.emplace_back(minw[i - 1]);
            else
                minw.emplace_back(v[i]);
        for (int i = 0; i < n; i++)
        {
            int std = (lower_bound(v.begin(), v.end(), standard(v[i]), comp) - v.begin() - 1);
            int rev = (lower_bound(v.begin(), v.end(), reverse(v[i]), comp) - v.begin() - 1);
            //cout << std << " " << rev;

            if (std >= 0 && std < n)
                if (minw[(int)std].w < v[i].w)
                    r[v[i].id] = minw[std].id;

            if (rev >= 0 && rev < n)
                if (minw[(int)rev].w < v[i].h)
                {
                    r[v[i].id] = minw[rev].id;
                }
        }

        for (int i = 1; i <= n; i++)
            cout << r[i] << " \n"[i == n];
    }
}