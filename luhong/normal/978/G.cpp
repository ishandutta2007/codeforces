#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
struct xxx{int l,r,c,id;}d[10100];int used[10100];int ans[10100];
bool cmp(xxx a,xxx b){return a.r<b.r;}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&d[i].l,&d[i].r,&d[i].c);d[i].id=i;
		
	}
	sort(d+1,d+m+1,cmp);
	for(int i=1;i<=m;i++)used[d[i].r]=i;
	for(int i=1;i<=n;i++)
	{
		if(used[i])
		{
			if(d[used[i]].c==0)
			{
				ans[i]=m+1;
			}
			else return 0*puts("-1");
		 } 
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(d[j].c>0&&i>=d[j].l){ans[i]=d[j].id;d[j].c--;break;}
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}