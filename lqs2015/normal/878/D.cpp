#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[22][111111],r[111111][22],tp,x,y,cnt,cur,msk;
pair<int,int> g[22];
bitset<4111> b[111111];
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<k;j++) g[j]=make_pair(a[j][i],j);
		sort(g,g+k);
		reverse(g,g+k);
		for (int j=0;j<k;j++) r[i][j]=g[j].second;
	}
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<(1<<k);j++)
		{
			if (j&(1<<i)) b[i][j]=1;
		}
	}
	cnt=k;
	while(q--)
	{
		scanf("%d%d%d",&tp,&x,&y);
		x--;y--;
		if (tp==1) b[cnt++]=b[x]|b[y];
		else if (tp==2) b[cnt++]=b[x]&b[y];
		else
		{
			cur=0;msk=0;
			while(!b[x][msk])
			{
				msk|=(1<<r[y][cur]);
				cur++;
			}
			cur--;
			printf("%d\n",a[r[y][cur]][y]);
		}
	}
	return 0;
}