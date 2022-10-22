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
int n;
int sum[15000005];
int a[15000005];
bool b[150005];
int prime[150005];

int shaiprime(int a[],int n)
{
//	bool b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=true;
	}
	for(int i=2;i<n;i++)
	{
		if(!b[i]) continue;
		for(int j=i+i;j<n;j+=i)
		{
			b[j]=false;
		}
	}
	int k=0;
	for(int i=2;i<n;i++)
	{
		if(b[i]) a[k++]=i;
	}
	return k;
}

void calc(int x)
{
	int t=x;
//	cout<<t<<endl;
	for(int i=0;prime[i]*prime[i]<=x;i++)
	{
		if(t%prime[i]==0) sum[prime[i]]++;
		while(t%prime[i]==0)
		{
			t/=prime[i];
//			cout<<prime[i]<<' ';
		}
	}
//	cout<<t<<endl;
	if(t!=1) sum[t]++;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int gcd=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		if(gcd==-1)
		{
			gcd=a[i];
		}
		else
		{
			gcd=__gcd(gcd,a[i]);
		}
//		cout<<gcd<<endl;
	}
//	cout<<gcd<<endl;
	for(int i=0;i<n;i++)
	{
		a[i]/=gcd;
	}
	int k=shaiprime(prime,150000);
	for(int i=0;i<n;i++)
	{
		calc(a[i]);
	}
	int res=inf;
//	cout<<gcd<<endl;
//	cout<<prime[0]<<endl;
	for(int i=0;i<=15000000;i++)
	{
		res=min(res,n-sum[i]);
	}
	if(res==n) over(-1);
	cout<<res<<endl;
	return 0;
}