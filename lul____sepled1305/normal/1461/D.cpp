/** Ithea best girl **/

#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;

int com_search(int mini,int maxi, map<int,int> &mp,vector<pii> &v)
{
    //cout<<mini<<' '<<maxi<<endl;
    if(mini > maxi)
        return 0;
    if(mini == maxi)
    {
        mp.insert({v[mini].second,0});
        return v[mini].second;
    }

    int mid = v[mini].first + v[maxi].first >> 1;
    int mi = 0, ma = v.size() - 1;
    while(mi < ma)
    {
        int md = mi + ma >> 1;
        //cout<<"SM: "<<mi<<' '<<ma<<' '<<md<<endl;
        if(md == mi)
        {
            if(v[ma].first > mid)
                ma = mi;
            else
                mi = ma;
        }
        else
        {
            if(v[md].first > mid)
                ma = md;
            else
                mi = md;
        }
    }
    int sum = 0;
    sum += com_search(mini,mi,mp,v);
    sum += com_search(mi+1,maxi,mp,v);
    mp.insert({sum,0});
    return sum;
}

void solve()
{
    int n,q,i,j;
    cin>>n>>q;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<pii> v;
    int last = -1;
    for(i=0;i<n;i++)
    {
        if(a[i] != last)
            v.push_back({a[i],0}),last = a[i];
        v.back().second+=a[i];
    }
    map<int, int> mp;
    com_search(0,v.size()-1,mp,v);
    for(i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(mp.count(a))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}