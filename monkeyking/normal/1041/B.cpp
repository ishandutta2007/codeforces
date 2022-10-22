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

ll gcd(ll a,ll b)
{
	if(a<=0 || b<=0)
	{
		printf("math::gcd(%d,%d) got error!!two varible can not below or equal to 0.\n",a,b);
		exit(0);
	}
	ll c=a%b;
	while(c)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
	ll x1=x,y1=y;
	ll z=__gcd(x1,y1);
	x/=z;
	y/=z;
	ll c=min(a/x,b/y);
	cout<<c<<endl;
	return 0;
}