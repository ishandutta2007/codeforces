#include<bits/stdc++.h>
using namespace std;
#define int long long
int suma[100001],sumb[100001];
main()
{
    string s;
    cin>>s;
    int n=s.length();
    s=' '+s;
    for(int x=1;x<=n;x++)
    if(s[x]=='a')suma[x]=suma[x-1]+1,sumb[x]=sumb[x-1];
    else suma[x]=suma[x-1],sumb[x]=sumb[x-1]+1;
    int ans=0;
    for(int x=1;x<=n;x++)
    for(int y=x-1;y<=n;y++)
    //[1,x),[x,y],(y,n]
    ans=max(ans,suma[x-1]+sumb[y]-sumb[x-1]+suma[n]-suma[y]);
    cout<<ans<<endl;
}