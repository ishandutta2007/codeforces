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
const int mod=1e9+9;
using namespace std;
int n,h;
int dp[1005][32][32][32][2];

void add(int &a,const int b)
{
	a+=b;
	if(a>=mod) a-=mod;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>h;
	dp[1][2][2][2][0]=4;
	for(int i=1;i<n;i++)
	{
		for(int j=2;j<=h+1;j++)
		{
			for(int l=j;l<=h+1;l++)
			{
				for(int o=l;o<=h+1;o++)
				{
					for(int p=0;p<2;p++)
					{
						int temp=dp[i][j][l][o][p];
						int ni=(j>h?j:j+1);
						int nj=(l>h?l:l+1);
						int nl=(o>h?o:o+1);
//						if(i==3 && j==2 && l==2 && o==2 && p==0) cout<<i+1<<' '<<ni<<' '<<nj<<' '<<nl<<endl;
						add(dp[i+1][ni][nj][nl][p],temp);
						if(p==0)
						{
							add(dp[i+1][(2)][nj][nl][j>h],temp);
							add(dp[i+1][(2)][ni][nl][l>h],temp);
							add(dp[i+1][(2)][ni][nj][o>h],temp);
						}
						else
						{
							add(dp[i+1][nj][nl][h+1][j>h],temp);
							add(dp[i+1][ni][nl][h+1][l>h],temp);
							add(dp[i+1][ni][nj][h+1][o>h],temp);
						}
					}
				}
			}
		}
	}
	int res=0;
	for(int i=2;i<=h+1;i++)
	{
		for(int j=i;j<=h+1;j++)
		{
			for(int l=j;l<=h+1;l++)
			{
				for(int o=0;o<2;o++)
				{
					add(res,dp[n][i][j][l][o]);
				}
			}
		}
	}
	res-=dp[n][h+1][h+1][h+1][1];
	if(res<0) res+=mod;
	cout<<res<<endl;
	return 0;
}