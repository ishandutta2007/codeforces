#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n,m;
int use[maxn+5];
string s[maxn+5],t[maxn+5];
string out[maxn+5];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		t[i]=s[i];
		reverse(t[i].begin(),t[i].end());
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(use[i]) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(use[j]) continue;
			if(s[i]==t[j]) use[i]=j,use[j]=i,ans+=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i]) continue;
		if(s[i]==t[i])
		{
			use[i]=i;
			ans++;
			break;
		}
	}
	printf("%d\n",ans*m);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(use[i]==i) continue;
		if(use[i]) 
		{
			tot++;
			out[tot]=s[i];
			out[ans-tot+1]=t[i];
			use[use[i]]=0;
			use[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i]==i) 
		{
			out[(ans+1)/2]=s[i];
			break;
		}
	}
	for(int i=1;i<=ans;i++) cout<<out[i];
	cout<<endl;
	return 0;
}