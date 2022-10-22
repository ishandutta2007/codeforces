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
int m,n;
int bit[400005];
vector <int> vec;
vector <pair<int,int> >data;
int nn;
int dp[200005];
map <int,int> id;
const int mod=1e9+7;

bool compare(const pii a,const pii b)
{
	return a.second<b.second;
}

void add(int x,int delta)
{
	while(x<=nn)
	{
		bit[x]+=delta;
		bit[x]%=mod;
		x+=x & -x;
	}
}

ll query(int x)
{
	ll res=0;
	while(x)
	{
		res+=bit[x];
		res%=mod;
		x&=(x-1);
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>m>>n;
	if(n==0) over(0);
	int l,r;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&l,&r);
		data.push_back(mp(l,r));
		vec.push_back(l);
		vec.push_back(r);
	}
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	for(int i=0;i<vec.size();i++)
	{
		id[vec[i]]=i+1;
	}
	sort(all(data),compare);
	nn=1;
	while(nn<vec.size())
	{
		nn<<=1;
	}
//	cout<<nn<<endl;
	if(vec[0]!=0)
	{
		over(0);
	}
	if(vec[vec.size()-1]!=m)
	{
		over(0);
	}
	dp[1]=1;
	add(1,1);
//	cout<<endl;
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i]<<' '<<id[vec[i]]<<endl;
//	}
	for(int i=0;i<n;i++)
	{
//		cout<<i<<endl;
		r=data[i].second;
		l=data[i].first;
		r=id[r];
		l=id[l];
		ll t=query(r-1)-query(l-1);
		t%=mod;
		t=(t+mod)%mod;
		dp[r]+=t;
		dp[r]%=mod;
		add(r,t);
	}
//	cout<<dp[1]<<' '<<dp[2]<<' '<<dp[3]<<endl;
	cout<<dp[vec.size()]<<endl;
	return 0;
}