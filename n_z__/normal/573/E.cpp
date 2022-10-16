#include<bits/stdc++.h>
#define int long long
using namespace std;int f[100001];main(){int n;cin>>n;int ans=0;memset(f,0x8f,sizeof(f));f[0]=0;for(int i=1,x;i<=n;i++){cin>>x;for(int j=i;j;j--)f[j]=max(f[j],f[j-1]+x*j),ans=max(ans,f[j]);}cout<<ans;}