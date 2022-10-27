// LUOGU_RID: 91292912
#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int x=0;x<n;x++)
    cin>>a[x];
    for(int x=0;x<=20;x++)
    for(int y=0;y<n;y++)
    if(y&(1<<x))a[y]^=a[y^(1<<x)];
    for(int x=0;x<=20;x++)
    for(int y=0;y<n;y++)
    if(y&(1<<x))a[y^(1<<x)]^=a[y];
    for(int x=n-1;x>=0;x--)
    cout<<a[x]<<' ';
}