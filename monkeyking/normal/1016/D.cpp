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
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
int a[105];
int b[105];
int res[105][105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",b+i);
	}
	int clash=0;
	for(int i=0;i<=31;i++)
	{
		int mask=(1<<i);
		bool f=0;
//		cout<<i<<":";
		for(int j=0;j<n;j++)
		{
			f^=(bool)(mask & a[j]);
//			cout<<(mask & a[j])<<' ';
		}
//		cout<<endl;
//		cout<<f<<endl;
		for(int j=0;j<m;j++)
		{
			f^=(bool)(mask & b[j]);
		}
		if(f) over("NO");
		for(int j=0;j<n;j++)
		{
//			cout<<(mask & a[j])<<' '<<i<<' '<<j<<endl;
			res[j][0]+=(mask & a[j]);
		}
		for(int j=1;j<m;j++)
		{
			res[0][j]+=(mask & b[j]);
		}
		clash+=(mask & b[0]);
	}
	clash=a[0];
	for(int i=1;i<m;i++)
	{
		clash^=res[0][i];
	}
	res[0][0]=clash;
//	clash^=res[0][0];
//	cout<<clash<<endl;
//	res[1][0]^=clash;
//	res[1][1]=clash;
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",res[i][j]);
		}
		cout<<endl;
	}
	return 0;
}