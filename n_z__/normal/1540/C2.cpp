#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
int b[101],c[101],f[10001],g[10001],w[101];
unordered_map<int,int>mp;
main(){
    int n;
	cin>>n;
	int s=1;
	for(int x=1;x<=n;x++)
	cin>>c[x],(s*=c[x]+1)%=p;
	for(int x=1;x<n;x++)
	cin>>b[x];
	for(int x=1;x<=n;x++)
	for(int y=1;y<x;y++)
	w[x]+=(x-y)*b[y];
	int l=-(w[n]+n-1)/n,r=(n*101-w[n]+n-1)/n;
	for(int e=l;e<=r;e++)
	{
        for(int x=0;x<=10000;x++)
        g[x]=1;
        for(int x=1;x<=n;x++)
        {
            memset(f,0,sizeof(f));
            for(int y=max(0ll,x*e+w[x]);y<=10000;y++)
            f[y]=(g[y]-(y-c[x]>=1)*g[y-c[x]-1]%p+p)%p;
            for(int y=0;y<=10000;y++)
            g[y]=(f[y]+(y>=1)*g[y-1])%p;
        }
        mp[e]=g[10000];
	}
	int q;
	cin>>q;
	while(q--)
	{
	    int x;
	    cin>>x;
	    cout<<(x<l)*s+(x>=l&&x<=r)*mp[x]<<endl;
	}
}