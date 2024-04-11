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
int n,k;
int a[100005];
bool wk[100005];
int sum[100005];
int kn[100005];
int add[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&k);
	rep(n)
	{
		scanf("%d",a+i);
	}
	rep(n)
	{
		scanf("%d",wk+i);
	}
	add[0]=a[0]*(1-wk[0]);
	for(int i=1;i<k;i++)
	{
		add[i]=add[i-1]+a[i]*(1-wk[i]);
	}
	for(int i=k;i<n;i++)
	{
//		cout<<i<<' '<<add[i-1]<<' '<<a[i]*(1-wk[i])<<' '<<a[i-k]*(1-wk[i])<<endl;
		add[i]=add[i-1]+a[i]*(1-wk[i])-a[i-k]*(1-wk[i-k]);
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<add[i]<<' ';
//	}
//	cout<<endl;
	int res=0;
	for(int i=0;i<n;i++)
	{
		res=max(res,add[i]);
	}
//	cout<<res<<endl;
	for(int i=0;i<n;i++)
	{
		res+=wk[i]*a[i];
	}
	cout<<res<<endl;
	return 0;
}