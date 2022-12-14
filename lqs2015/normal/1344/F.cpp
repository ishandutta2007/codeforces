#include<bits/stdc++.h>
using namespace std;
bitset<2222> mat[2222],res;
int n,k,x[2222],y[2222],len,r[2222],cnt,msk,upper;
char opt[55],c[55];
bool fre[2222];
bool gauss()
{
	upper=1;
	for (int i=1;i<=2*n;i++)
	{
		int pos=-1;
		for (int j=upper;j<=cnt;j++)
		{
			if (mat[j][i]) 
			{
				pos=j;
				break;
			}
		}
		if (!~pos) 
		{
			fre[i]=1;
			continue;
		}
		swap(mat[upper],mat[pos]);
		for (int j=upper+1;j<=cnt;j++)
		{
			if (mat[j][i]) mat[j]^=mat[upper];
		}
		upper++;
	}
	upper--;int lst;
	for (int i=2*n;i>=1;i--)
	{
		if (fre[i]) continue;
		lst=mat[upper][2*n+1];
		for (int j=2*n;j>i;j--)
		{
			if (mat[upper][j]) lst^=res[j];
		}
		res[i]=lst;upper--;
	}
	for (int i=1;i<=cnt;i++)
	{
		lst=0;
		for (int j=1;j<=2*n;j++)
		{
			if (mat[i][j]) lst^=res[j];
		}
		if (lst!=mat[i][2*n+1]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=2*n;i++) 
	{
		x[i]=1;y[i]=0;
	} 
	for (int i=1;i<=k;i++)
	{
		scanf("%s",opt);
		if (opt[0]=='m')
		{
			scanf("%d",&len);
			for (int j=1;j<=len;j++)
			{
				scanf("%d",&r[j]);
			}
			scanf("%s",c);
			if (c[0]=='W') msk=0;
			else if (c[0]=='R') msk=1;
			else if (c[0]=='B') msk=2;
			else msk=3;
			++cnt;
			for (int j=1;j<=len;j++)
			{
				if (x[(r[j]<<1)-1]) mat[cnt][(r[j]<<1)-1]=1-mat[cnt][(r[j]<<1)-1];
				if (y[(r[j]<<1)-1]) mat[cnt][(r[j]<<1)]=1-mat[cnt][(r[j]<<1)]; 
			}
			mat[cnt][2*n+1]=(msk>>1);
			++cnt;
			for (int j=1;j<=len;j++)
			{
				if (x[r[j]<<1]) mat[cnt][r[j]<<1]=1-mat[cnt][r[j]<<1];
				if (y[r[j]<<1]) mat[cnt][(r[j]<<1)-1]=1-mat[cnt][(r[j]<<1)-1]; 
			}
			mat[cnt][2*n+1]=(msk&1);
		}
		else if (opt[0]=='R' && opt[1]=='Y')
		{
			scanf("%d",&len);
			for (int j=1;j<=len;j++)
			{
				scanf("%d",&r[j]);
				x[(r[j]<<1)-1]^=y[r[j]<<1];
				y[(r[j]<<1)-1]^=x[r[j]<<1];
			}
		}
		else if (opt[0]=='R' && opt[1]=='B')
		{
			scanf("%d",&len);
			for (int j=1;j<=len;j++)
			{
				scanf("%d",&r[j]);
				swap(x[(r[j]<<1)-1],y[r[j]<<1]);
				swap(x[r[j]<<1],y[(r[j]<<1)-1]);
			}
		}
		else
		{
			scanf("%d",&len);
			for (int j=1;j<=len;j++)
			{
				scanf("%d",&r[j]);
				x[r[j]<<1]^=y[(r[j]<<1)-1];
				y[r[j]<<1]^=x[(r[j]<<1)-1];
			}
		}
	}
	if (!gauss())
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i=1;i<=n;i++)
	{
		if (res[(i<<1)-1]&res[i<<1]) putchar('Y');
		else if (!res[(i<<1)-1] && !res[i<<1]) putchar('.');
		else if (res[i<<1]) putchar('R');
		else putchar('B');
	}
	putchar('\n');
	return 0;
}