#include<bits/stdc++.h>
using namespace std;
const int maxn=50,mod=1e9+7;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int r,p[4],sum,mat[222][222],re[111][111][222],cnt,pos,cur[222],ct,x[222];
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod; 
	}
	return res;
}
bool can(int x,int y)
{
	return (x*x+y*y<=r*r);
}
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
void gauss()
{
	for (int i=1;i<=ct;i++)
	{
		int pos=-1;
		for (int j=i;j<=ct;j++)
		{
			if (mat[j][i]) 
			{
				pos=j;
				break;
			}
		}
		if (!~pos) continue;
		for (int j=i;j<=cnt;j++) swap(mat[i][j],mat[pos][j]);
		for (int j=i+1;j<=ct;j++)
		{
			int coef=-1ll*mat[j][i]*binpow(mat[i][i],mod-2)%mod;
			for (int k=i;k<=cnt;k++)
			{
				add(mat[j][k],1ll*mat[i][k]*coef%mod);
			}
		}
	}
	x[cnt]=1;
	for (int i=ct;i>=1;i--)
	{
		int lst=0;
		for (int j=cnt;j>i;j--)
		{
			add(lst,-1ll*x[j]*mat[i][j]%mod);
		}
		x[i]=1ll*lst*binpow(mat[i][i],mod-2)%mod;
	}
}
int main()
{
	scanf("%d",&r);
	for (int i=0;i<4;i++)
	{
		scanf("%d",&p[i]);
		sum+=p[i];
	}
	for (int i=0;i<4;i++)
	{
		p[i]=1ll*p[i]*binpow(sum,mod-2)%mod;
	}
	if (!r) 
	{
		printf("1\n");
		return 0;
	}
	for (int i=-r;i<=r;i++)
	{
		if (can(i,0))
		{
			cnt++;
			re[maxn+i][maxn][cnt]=1;
			if (!i) pos=cnt;
		}
	}
	for (int i=-r;i<=r;i++)
	{
		if (can(i,1))
		{
			cnt++;
			re[maxn+i][maxn+1][cnt]=1;
		}
	}
	cnt++;
	for (int j=1;j<=r;j++)
	{
		for (int i=-r;i<=r;i++)
		{
			if (!can(i,j)) continue;
			for (int k=1;k<=cnt;k++) cur[k]=re[maxn+i][maxn+j][k];
			cur[cnt]--;
			for (int k=0;k<4;k++)
			{
				if (k==3) continue;
				int xx=i+dx[k],yy=j+dy[k];
				if (!can(xx,yy)) continue;
				for (int h=1;h<=cnt;h++) add(cur[h],-1ll*re[maxn+xx][maxn+yy][h]*p[k]%mod);
			}
			int xx=i+dx[3],yy=j+dy[3];
			if (!can(xx,yy))
			{
				ct++;
				for (int k=1;k<=cnt;k++) mat[ct][k]=cur[k];
			}
			else
			{
				for (int k=1;k<=cnt;k++) re[maxn+xx][maxn+yy][k]=1ll*binpow(p[3],mod-2)*cur[k]%mod;
			}
		}
	}
	for (int j=0;j>=-r;j--)
	{
		for (int i=-r;i<=r;i++)
		{
			if (!can(i,j)) continue;
			for (int k=1;k<=cnt;k++) cur[k]=re[maxn+i][maxn+j][k];
			cur[cnt]--;
			for (int k=0;k<4;k++)
			{
				if (k==1) continue;
				int xx=i+dx[k],yy=j+dy[k];
				if (!can(xx,yy)) continue;
				for (int h=1;h<=cnt;h++) add(cur[h],-1ll*re[maxn+xx][maxn+yy][h]*p[k]%mod);
			}
			int xx=i+dx[1],yy=j+dy[1];
			if (!can(xx,yy))
			{
				ct++;
				for (int k=1;k<=cnt;k++) mat[ct][k]=cur[k];
			}
			else
			{
				for (int k=1;k<=cnt;k++) re[maxn+xx][maxn+yy][k]=1ll*binpow(p[1],mod-2)*cur[k]%mod;
			}
		}
	}
	/*for (int i=-1;i<=1;i++)
	{
		for (int j=-1;j<=1;j++)
		{
			if (can(i,j)) 
			{
				cout<<i<<" "<<j<<" ";
				for (int k=1;k<=cnt;k++) cout<<re[maxn+i][maxn+j][k]<<" ";
				cout<<endl;
			}
		}
	}*/
	gauss();
	printf("%d\n",x[pos]);
	return 0;
}