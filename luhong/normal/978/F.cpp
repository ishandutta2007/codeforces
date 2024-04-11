#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
int n,k,r[201000];struct xxx {int r,id;}d[201000];
int x[201000],y[201000],a[201000],nxt[201000],b[201000];
bool cmp(xxx a,xxx b){return a.r>b.r;}
vector<int> v[201000];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&d[i].r),d[i].id=i;sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++)a[d[i].id]=i;
	for(int i=n;i>=1;i--)if(d[i].r==d[i+1].r)nxt[i]=nxt[i+1];else nxt[i]=i;
	for(int i=1;i<=k;i++)scanf("%d%d",&x[i],&y[i]),x[i]=a[x[i]],y[i]=a[y[i]];
	for(int i=1;i<=k;i++)
	{
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int len=v[i].size();int tot=0;
		for(int k=0;k<len;k++)
		{
			if(v[i][k]>nxt[i])tot++;
		}
		b[d[i].id]=n-nxt[i]-tot;
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	return 0;
}