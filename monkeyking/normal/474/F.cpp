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
const int inf=1039741802;
using namespace std;
int n;
int m;
int a[400005];
pair<int,int> datg[400005];

int gcd(int a,int b)
{
	if(a==0 || b==0) return max(a,b);
	if(a<b) swap(a,b);
	int c=a%b;
	while(1)
	{
		if(c==0) break;
		if(a==b) break;
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

pii dfsg(int x)
{
	if(x<m/2)
	{
		pii a=dfsg(2*x+1);
		pii b=dfsg(2*x+2);
		int c=gcd(a.first,b.first);
		if(c!=a.first && c!=b.first) return datg[x]=mp(c,0);
		if(a.first==b.first) return datg[x]=mp(c,a.second+b.second);
		if(c==a.first) return datg[x]=mp(c,a.second);
		return datg[x]=mp(c,b.second);
	}
	else
	{
		if(m/2+n>x) return datg[x]=mp(a[x-m/2],1);else return datg[x]=mp(a[x-m/2],0);
	}
}

pii query(int x,int l,int r,int gl,int gr)
{
//	cout<<x<<' '<<l<<' '<<r<<' '<<gl<<' '<<gr<<endl;
	if(gl<=l && gr>=r) return datg[x];
	if(r<=gl) return mp(0,0);
	if(l>=gr) return mp(0,0);
	pii a=query(2*x+1,l,(l+r)/2,gl,gr);
	pii b=query(2*x+2,(l+r)/2,r,gl,gr);
	int c=gcd(a.first,b.first);
	if(c!=a.first && c!=b.first) return mp(c,0);
	if(a.first==b.first) return mp(c,a.second+b.second);
	if(c==a.first) return mp(c,a.second);
	return mp(c,b.second);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	m=1;
	while(m<n)
	{
		m*=2;
	}
	m=m*2-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=n;i<m;i++)
	{
		a[i]=a[i-1];
	}
	dfsg(0);
//	for(int i=0;i<m;i++)
//	{
//		cout<<datg[i].first<<'-'<<datg[i].second<<' ';
//	}
//	cout<<endl;
	int q;
	cin>>q;
	int l,r;
//	cout<<query(0,1,5,0,8).second<<endl;
	while(q--)
	{
		scanf("%d%d",&l,&r);
//		if(l==r)
//		{
//			printf("0\n");
//			continue;
//		}
		l--;
		pii a=query(0,0,m/2+1,l,r);
		printf("%d\n",r-l-a.second);
	}
	return 0;
}