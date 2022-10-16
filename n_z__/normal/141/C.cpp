#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<pair<int,int>,string>a[100001];
main()
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x].second>>a[x].first.first;
    sort(a+1,a+1+n);
    for(int x=1;x<=n;x++)
    {
        if(a[x].first.first>=x)return puts("-1"),0;
        a[x].first.second=x-a[x].first.first;
        for(int y=1;y<x;y++)
        if(a[x].first.second<=a[y].first.second)a[y].first.second++;
    }
    for(int x=1;x<=n;x++)
    cout<<a[x].second<<' '<<a[x].first.second<<endl;
}