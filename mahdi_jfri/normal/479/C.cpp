#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll, ll> a,pair<ll, ll>b)
{
    return (a.first<b.first) || (a.first==b.first && a.second<b.second);
}
pair<ll,ll>a[5100];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,cmp);
    ll b=0;
    for(int i=0;i<n;i++)
    {
        if(b <= a [i].second)
            b=a[i].second;
        else
            b=a[i].first;
    }
    cout<<b;
}