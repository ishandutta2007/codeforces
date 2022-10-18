#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a[n];
    for(int x=0;x<n;x++)
    for(int y=0;y<k;y++)
    {
        int z;
        cin>>z;
        a[x].push_back(z);
    }
    map<vector<int>,int>mp;
    for(int x=0;x<n;x++)
    for(int y=0;y<x;y++)
    {
        vector<int>q;
        for(int z=0;z<k;z++)
        q.push_back((6-a[x][z]-a[y][z])%3);
        mp[q]++;
    }
    int ans=0;
    for(int x=0;x<n;x++)
    ans+=mp[a[x]]*(mp[a[x]]-1)/2;
    cout<<ans<<endl;
}