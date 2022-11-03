#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define X first
#define Y second
const int maxn = 2e5 + 20;
vector<pair<pair< ll , ll> , ll> > a;
vector<pair<ll , ll> > l[maxn] , r[maxn];
vector<ll> pmin1[maxn] , pmin2[maxn];
ll res = 1e18;
int main()
{
    int n , x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        int le , ri , cost;
        cin >> le >> ri >> cost;
        l[ri - le + 1].pb({le , cost});
        r[ri - le + 1].pb({ri , cost});
        a.pb({{le , ri} , cost});
    }
    for(int i = 0; i < maxn; i++)
    {
        if(l[i].empty())
            continue;
        sort(l[i].begin() , l[i].end());
        sort(r[i].begin() , r[i].end());
        pmin1[i].pb(l[i].back().second);
        pmin2[i].pb(r[i][0].second);
        for(int j = 1; j < l[i].size(); j++)
            pmin2[i].pb(min(pmin2[i].back() , r[i][j].Y));
        for(int j = (int)l[i].size() - 2; j >= 0; j--)
            pmin1[i].pb(min(pmin1[i].back() , l[i][j].Y));
        reverse(pmin1[i].begin() , pmin1[i].end());
    }
    for(auto seg : a)
    {
        if(seg.Y >= res)
            continue;
        int t = seg.X.Y - seg.X.X + 1;
        if(t >= x)
            continue;
        pair<ll , ll> seg2;
        seg2.first = seg.X.X;
        seg2.second = -1;
        int k = upper_bound(r[x - t].begin() , r[x - t].end() , seg2)-r[x - t].begin();
        if(k < pmin2[x - t].size() && k > -1 && r[x - t][k].X >= seg2.X)
            k--;
        if(k < pmin2[x - t].size() && k > -1)
            res = min(res , (ll)pmin2[x - t][k] + (ll)seg.Y);
        seg2.first = seg.X.Y;
        seg2.second = 1e18;
        k = upper_bound(l[x - t].begin() , l[x - t].end() , seg2)-l[x - t].begin();
        if(k < pmin1[x - t].size() && k > -1)
            res = min(res , pmin1[x - t][k] + seg.Y);
    }
    cout << (res == 1e18? -1 : res) << endl;
}