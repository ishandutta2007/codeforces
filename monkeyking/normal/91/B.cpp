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
const int v=300;
int b[100005/v+1][v+1];
int a[100005];
int n;
int m[100005/v+1];

int query(int l,int r,int x)
{
	if(l/v==r/v)
	{
		for(int i=r-1;i>=l;i--)
		{
			if(a[i]<x) return i;
		}
		return -1;
	}
	int nr=r;
	while(nr>0)
	{
		if(nr%v==0) break;
		nr--;
		if(a[nr]<x) return nr;
	}
	while(nr-v>=l)
	{
		nr-=v;
//		cout<<(nr/v)<<endl;
		if(m[nr/v]<x)
		{
			int nl=nr;
			nr=nr+v;
			for(int i=nr-1;i>=nl;i--)
			{
				if(a[i]<x) return i;
			}
		}
	}
	for(int i=nr-1;i>=l;i--)
	{
		if(a[i]<x) 
		{
			return i;
		}
	}
	return -1;
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(m,0x3f,sizeof(m));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		b[i/v][i%v]=a[i];
		m[(int)(i/v)]=min(m[(int)(i/v)],a[i]);
	}
	int o=(n+v-1)/v;
	for(int i=0;i<n;i++)
	{
		int k=query(i+1,n,a[i]);
		if(k==-1) printf("-1 ");else printf("%d ",k-i-1);
	}
	return 0;
}