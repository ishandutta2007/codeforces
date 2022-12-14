#include<iostream>
using namespace std;
int n,a,b,len[15],con[11],ans,num[11];
void doit()
{
	int cur=0;
	for (int i=1;i<=6;i++) num[i]=0;
	for (int i=1;i<=6;i++)
	{
		if (num[con[i]]==0) cur++;
		num[con[i]]+=len[i];
	}
	for (int i=1;i<=6;i++) if (num[i]>n) return;
	ans=min(ans,cur);
}
void dfs(int i)
{
	if (i==7) 
	{
		doit();
		return;
	}
	for (int j=1;j<=6;j++) 
	{
		con[i]=j;
		dfs(i+1);
	}
}
int main()
{
	cin>>n>>a>>b;ans=1e9;
	len[1]=len[2]=len[3]=len[4]=a;len[5]=len[6]=b;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}