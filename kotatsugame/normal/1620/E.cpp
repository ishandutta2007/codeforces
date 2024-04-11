#include<iostream>
using namespace std;
int pr[5<<17];
int Q;
int t[5<<17],x[5<<17],y[5<<17];
int ans[5<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>Q;
	int len=0;
	for(int i=0;i<Q;i++)
	{
		cin>>t[i]>>x[i];
		if(t[i]==2)cin>>y[i];
		else len++;
	}
	for(int i=1;i<5<<17;i++)pr[i]=i;
	int n=len;
	for(int i=Q;i--;)
	{
		if(t[i]==1)
		{
			len--;
			ans[len]=pr[x[i]];
		}
		else
		{
			pr[x[i]]=pr[y[i]];
		}
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<(i+1==n?"\n":" ");
}