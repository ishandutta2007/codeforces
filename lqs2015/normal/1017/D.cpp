#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q,cnt[5555],cur,wu[5555],ans[5555][111],pos,curans,k;
pair<int,int> ab[5555];
char s[111];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=n-1;i>=0;i--) scanf("%d",&wu[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s);
		cur=0;
		for (int j=0;j<n;j++) cur=cur*2+(s[j]-'0');
		cnt[cur]++;
	}
	for (int i=0;i<(1<<n);i++)
	{
		cur=0;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j)) cur+=wu[j];
		}
		ab[i]=make_pair(cur,i);
	}
	sort(ab,ab+(1<<n));
	for (int i=0;i<(1<<n);i++)
	{
		pos=0;curans=0;
		for (int j=0;j<=100;j++)
		{
			while(pos<(1<<n) && ab[pos].first<=j)
			{
				curans+=cnt[(1<<n)-1-(ab[pos].second^i)];
				pos++;
			}
			ans[i][j]=curans;
		}
	}
	while(q--)
	{
		scanf("%s%d",s,&k);
		cur=0;
		for (int i=0;i<n;i++) cur=cur*2+(s[i]-'0');
		printf("%d\n",ans[cur][k]);
	}
	return 0;
}