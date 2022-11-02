/**
    Ithea Myse Valgulious
**/

#include<bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using pll = pair<ll,ll>;
int T;

void solve()
{
    int n,i;
    cin>>n;
    int w[n];
    int deg[n];
    priority_queue<pii> pq;
    for(i=0;i<n;i++)
        cin>>w[i],deg[i] = 0;
    vector<int> v;
    ll sum = 0;
    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        deg[a]++,deg[b]++;
    }
    for(i=0;i<n;i++)
    {
        sum+=w[i];
        if(deg[i] == 1)
            continue;
        while(--deg[i]>0)
            v.push_back(w[i]);
    }
    sort(v.begin(),v.end());
    cout<<sum<<' ';
    for(i=0;i<n-2;i++)
    {
        if(!v.empty())
            sum+=v.back();
        cout<<sum<<' ';
        if(!v.empty())
            v.pop_back();
    }
    cout<<"\n";
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
        solve();
    return 0;
}