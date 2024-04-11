#include<bits/stdc++.h>
using namespace std;
#define int long long
double q[100001],f[100001],g[100001],s[101],t[101];
main() {
	int n,k;
    cin>>n>>k;
    for(int x=1;x<=k;x++)
    cin>>s[x]>>t[x];
	fill(f+1,f+1+n,1000000000);
    for(int x=1;x<=k;x++)
    {
        memcpy(g,f,sizeof(f[0])*(n+1));
        int l=0,r=0;
        for(int y=0,w=min(n*1.0,t[x]);y<=w;y++)
        {
            while(l<=r&&y-q[l]>t[x]-s[x])l++;
            while(l<=r&&g[(int)q[r]]>=g[y])r--;
            q[++r]=y;
            f[y]=min(f[y],g[(int)q[l]]+1);
            if(t[x]-y<=n)f[(int)t[x]-y]=min(f[(int)t[x]-y],g[(int)q[l]]+0.5);
        }
    }
    if(f[n]<=k)cout<<"Full"<<endl<<f[n]*2;
    else cout<<"Hungry";
}