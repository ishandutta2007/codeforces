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
int n,a,b;
int v[100005];
pii c[100005];
int sz;

bool ok(ll x)
{
//	cout<<a<<' '<<sz<<' '<<b<<' '<<x<<endl;
	return 1LL*a*sz>=1LL*b*x;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>a>>b;
	ll s=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",v+i);
		s+=v[i];
		c[i].first=v[i];
		c[i].second=i;
	}
	sz=v[0];
	sort(c,c+n);
	reverse(c,c+n);
	bool f=false;
	for(int i=0;i<n;i++)
	{
		if(ok(s))
		{
			cout<<i-f<<endl;
			return 0;
		}
		if(c[i].second!=0) s-=c[i].first;else f=1;
//		sz--;
	}
	cout<<n-1<<endl;
	return 0;
}