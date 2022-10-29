#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 205;

int n,m;
ll a[maxn][maxn],sum[maxn][maxn];

ll f[maxn][maxn],fi[maxn][maxn];

ll cal(int x,int y,int l,int r)
{
	if(l>r || x>y) return 0;
	return sum[y][r]-sum[y][l-1]-sum[x-1][r]+sum[x-1][l-1];
}

int fa[maxn];

void dfs(const int i,const int j,int ff)
{
	if(i>j) return;
	
	int k=fi[i][j];
	fa[k]=ff;
	dfs(i,k-1,k);
	dfs(k+1,j,k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) sum[i][j]+=sum[i-1][j];
	}
	
	for(int len=0;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if(len<=1)
			{
				f[i][j]=0;
				fi[i][j]=i;
				continue;
			}
			
			ll mn=LLONG_MAX;
			for(int k=i;k<=j;k++)
			{
				ll temp=f[i][k-1]+f[k+1][j];
				
				temp+= cal(i,k-1,1,i-1);
				temp+= cal(i,k-1,k,n);
				
				temp+= cal(k+1,j,1,k);
				temp+= cal(k+1,j,j+1,n);
				
				if( mn > temp )
				{
					mn=temp;
					fi[i][j]=k;
				}
			}
			f[i][j]=mn;
		}
	}
	dfs(1,n,0);
	for(int i=1;i<=n;i++) cout<<fa[i]<<" \n"[i==n];
	
	return 0;
}