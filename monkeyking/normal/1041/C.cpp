
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
int n,m,d;
int a[200005];
int now[200005];
pair<int,int> p[200005];

bool check(int x)
{
	int debug=(x==3);
	for(int i=0;i<x;i++)
	{
		now[i]=-1e9-7;
	}
	int k;
	for(int i=0;i<n;i++)
	{
		k=i%x;
		if(now[k]+d>=a[i])
		{
			return false;
		}
		now[k]=a[i];
	}
	return true;
}

void print(int x)
{
	cout<<x<<endl;
	int k;
	for(int i=0;i<n;i++)
	{
		k=i%x;
		now[p[i].second]=k;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",now[i]+1);
	}
	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>d;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		p[i].first=a[i];
		p[i].second=i;
	}
	sort(p,p+n);
	sort(a,a+n);
	int l=1,r=n,m,res=-1;
	while(l<=r)
	{
		m=l+r>>1;
		if(check(m))
		{
			res=m;
			r=m-1;
		}
		else
		{
			l=m+1;
		}
	}
	print(res);
	return 0;
}