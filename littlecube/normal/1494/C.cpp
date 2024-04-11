#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, pos[250005] = {0}, neg[250005] = {0}, posmax = 0, negmax = 0;
        vector<int> posa, posb, nega, negb;

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            if (a > 0)
                posa.emplace_back(a);
            else
                nega.emplace_back(-a);
        }
        for (int i = 1; i <= m; i++)
        {
            int a;
            cin >> a;
            if (a > 0)
                posb.emplace_back(a);
            else
                negb.emplace_back(-a);
        }
        sort(nega.begin(), nega.end());
        sort(negb.begin(), negb.end());

        for (int i = 0; i < posb.size(); i++)
        {
            auto iter = lower_bound(posa.begin(), posa.end(), posb[i]);
            if (iter != posa.end() && *iter == posb[i])
                pos[i]++;
            
        }

        for (int i = posb.size() - 1; i >= 0; i--)
            pos[i] += pos[i + 1];

        posmax = pos[0];

        for (int i = 0; i < posb.size(); i++)
        {
            int box = (upper_bound(posa.begin(), posa.end(), posb[i]) - posa.begin());
            int range = (int)(lower_bound(posb.begin(), posb.end(), posb[i] - box + 1) - posb.begin());
            if (box > 0)
                posmax = max(posmax, i - range + 1 + pos[i + 1]);
            else
                posmax = max(posmax, pos[i + 1]);
        }

        for (int i = 0; i < negb.size(); i++)
        {
            auto iter = lower_bound(nega.begin(), nega.end(), negb[i]);
            if (iter != nega.end() && *iter == negb[i])
                neg[i]++;
        }
        for (int i = negb.size() - 1; i >= 0; i--)
            neg[i] += neg[i + 1];

        for (int i = 0; i < negb.size(); i++)
        {
            int box = (upper_bound(nega.begin(), nega.end(), negb[i]) - nega.begin());
            int range = (int)(lower_bound(negb.begin(), negb.end(), negb[i] - box + 1) - negb.begin());
            if (box > 0)
                negmax = max(negmax, i - range + 1 + neg[i + 1]);
            else
                negmax = max(negmax, neg[i + 1]);
        }
        cout << posmax + negmax << '\n';
    }
}