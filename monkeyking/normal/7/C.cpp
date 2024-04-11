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

pair<int,int> exgcd(int a,int b)
{
	if(b==0) return mp(1,0);
	pii res=exgcd(b,a%b);
	return mp(res.second,res.first-(int)(a/b)*res.second);
}

int main()
{	
//	freopen("input.txt","r",stdin);
	ll a,b,c;
	cin>>a>>b>>c;
	c=-c;
	if(c<0)
	{
		a=-a;
		b=-b;
		c=-c;
	}
//	cout<<__gcd(a,b)<<endl;
	if(c%__gcd(a,b))
	{
		cout<<-1<<endl;
		return 0;
	}
//	if(c)
	pii res=exgcd(a,b);
	cout<<res.first*(c/__gcd(a,b))<<' '<<res.second*(c/__gcd(a,b));
//	cout<<res.first<<' '<<res.second<<endl;
	return 0;
}