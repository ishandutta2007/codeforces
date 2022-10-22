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
int n,k,d;
int a[500005];
int mx[500005];
int nxt[500005];
bool dp[500005];

int find(int x)
{
	return (nxt[x]==x?x:nxt[x]=find(nxt[x]));
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k>>d;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		nxt[i]=i;
	}
//	if(d==0)
//	{
//		if(k==1) over("YES\n") else over("NO\n");
//	}
	if(k==1) over("YES\n");
	nxt[n]=n;
	sort(a,a+n);
	int ed=0;
	for(int i=0;i<n;i++)
	{
		if(ed!=n)
		{
			while(a[i]+d>=a[ed])
			{
				ed++;
				if(ed==n) break;
			}
		}
		mx[i]=ed;
	}
	for(int i=k-1;i<mx[0];i++)
	{
		dp[i]=true;
		nxt[i]=i+1;
	}
//	cout<<nxt[6]<<' '<<find(6)<<endl;
	for(int i=1;i<n;i++)
	{
		if(dp[i]==false) continue;
		for(int j=i+k;j<mx[i+1];j=find(nxt[j]))
		{
			dp[j]=true;
			nxt[j]=j+1;
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<dp[i]<<' ';
//	}
//gwq2017
//	cout<<endl;
	if(dp[n-1]) cout<<"YES\n";else cout<<"NO\n";
	return 0;
}