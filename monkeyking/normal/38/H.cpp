#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int dist[55][55];
ll dp[55][55][55];
bool go[55],si[55],br[55];
int maxrk[55],minrk[55];
int n,m,k;

void solve()
{
	memset(dist,0x3f,sizeof(dist));
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		dist[x][y]=dist[y][x]=z;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		minrk[i]=inf;
		maxrk[i]=-inf;
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			minrk[i]=min(minrk[i],dist[i][j]*100+i);
			maxrk[i]=max(maxrk[i],dist[i][j]*100+i);
		}
//		cout<<minrk[i]<<' '<<maxrk[i]<<endl;
	}
	int g1,g2,s1,s2;
	ll res=0;
	cin>>g1>>g2>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			int gold=minrk[i];
			int bronze=maxrk[j];
			if(gold>=bronze) continue;
			memset(dp,0,sizeof(dp));
			for(int cur=0;cur<n;cur++)
			{
				go[cur]=(minrk[cur]<=gold);
				br[cur]=(maxrk[cur]>=bronze);
				si[cur]=false;
				for(int k=0;k<n;k++)
				{
					if(k==cur) continue;
					if(gold<(dist[cur][k]*100+cur) && (dist[cur][k]*100+cur)<bronze)
					{
						si[cur]=true;
						break;
					}
				}
//				si[cur]=!(maxrk[cur]<=gold || minrk[cur]>=bronze);
			}
			br[i]=si[i]=false;
			go[j]=si[j]=false;
//			cout<<gold<<' '<<bronze<<':'<<'\n';
//			for(int i=0;i<3;i++)
//			{
//				cout<<go[i]<<' '<<si[i]<<' '<<br[i]<<endl;
//			}
//			cout<<endl;
			dp[0][0][0]=1;
			for(int cur=0;cur<n;cur++)
			{
				for(int G=0;G<=cur;G++)
				{
					for(int B=0;B<=cur-G;B++)
					{
						if(go[cur])
						{
							dp[cur+1][G+1][B]+=dp[cur][G][B];
						}
						if(si[cur])
						{
							dp[cur+1][G][B]+=dp[cur][G][B];
						}
						if(br[cur])
						{
							dp[cur+1][G][B+1]+=dp[cur][G][B];
						}
					}
				}
			}
			for(int st=g1;st<=g2;st++)
			{
				for(int ed=s1;ed<=s2;ed++)
				{
					res+=dp[n][st][n-st-ed];
				}
			}
		}
	}
	cout<<res<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	solve();
	return 0;
}