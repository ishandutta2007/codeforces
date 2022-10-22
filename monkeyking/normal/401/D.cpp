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
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int m,n;
int a[20];
ll dp[(1<<18)][105];
int use;

int main()
{
//	freopen("input.txt","r",stdin);
	string c;
	cin>>c>>m;
	n=c.size();
	for(int i=0;i<n;i++)
	{
		a[i]=c[i]-'0';
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<m;j++)
		{
			use=0;
			for(int k=0;k<n;k++)
			{
				if(i==0 && a[k]==0) continue;
				if((i & (1<<k))) continue;
				if((use & (1<<a[k]))) continue;
				use|=(1<<a[k]);
				dp[i|(1<<k)][(j*10+a[k])%m]+=dp[i][j];
			}
		}
	}
	cout<<dp[(1<<n)-1][0]<<endl;
	return 0;
}