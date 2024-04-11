#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,l,a,t[100010],len[100010];
int main()
{
	cin>>n>>l>>a;int ans=0,i;t[n+1]=l;
	for (i=1;i<=n;i++) cin>>t[i]>>len[i];
	for (i=0;i<=n;i++) if (t[i]+len[i]+a<=t[i+1]) ans+=((t[i+1]-t[i]-len[i])/a);
	cout<<ans;
}