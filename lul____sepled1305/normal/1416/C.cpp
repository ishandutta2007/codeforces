/** Ogiso Setsuna best girl **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define int long long
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int n,i,j,maxi,cur = 1;
pii va[30];
 
void dfs(vector<pii> &v, int l, int r, int cur_pow, int val)
{
    vector<pii> m, n;
    int i;
    for(i=l;i<=r;i++)
    {
        pii it = v[i];
        if(it.first < val)
            m.push_back(it);
        else
            n.push_back(it);
    }
 
    int pointer =0, sum =0, inv = 0;
    i = 0;
    while(i < m.size())
    {
        while(pointer < n.size() && n[pointer].second < m[i].second)
        {
            pointer++;
        }
        i++;
        inv+=pointer;
    }
    int inv_v = 1LL*m.size() * n.size() - inv;
 
    va[cur_pow].first += inv;
    va[cur_pow].second += inv_v;
        for(i=0;i<m.size();i++)
        {
            v[i+l] = m[i];
        }
        if(cur_pow > 0 && m.size()!=0)
            dfs(v, l, l+m.size()-1, cur_pow-1, val/2);
        for(i=0;i<n.size();i++)
        {
            v[i+l+m.size()].first = n[i].first - val;
            v[i+l+m.size()].second = n[i].second;
        }
        if(cur_pow > 0 && n.size()!=0)
            dfs(v, l+m.size(), r, cur_pow-1, val/2);
 
}
 
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n;
    vector<pii> a;
    for(i=0;i<n;i++)
    {
        int b;
        cin>>b;
        a.push_back({b,i});
        maxi = max(maxi,a[i].first);
    }
    dfs(a,0,n-1,29,536870912);
    int cur =0, sum =0;
    for(i=29;i>=0;i--)
    {
        cur*=2;
        if(va[i].first > va[i].second)
            cur++;
        sum+=min(va[i].first,va[i].second);
    }
    cout<<sum<<' '<<cur<<endl;
    return chtholly;
}