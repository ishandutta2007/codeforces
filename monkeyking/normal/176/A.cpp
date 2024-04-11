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
const ll inf=103974182;
using namespace std;
ll n,m,k;
ll a[15][105];
ll b[15][105];
ll c[15][105];

bool compare(pii a,pii b)
{
	return a.first>b.first;
}

ll solve(ll x,ll y)
{
	pii t[m];
	for(ll i=0;i<m;i++)
	{
		t[i].first=b[y][i]-a[x][i];
		t[i].second=c[x][i];
	}
	sort(t,t+m,compare);
	ll res=0;
	ll remain=k;
	for(ll i=0;i<m;i++)
	{
		if(t[i].first<=0) return res;
		if(remain>t[i].second)
		{
			remain-=t[i].second;
			res+=t[i].second*t[i].first;
		}
		else
		{
			res+=remain*t[i].first;
			return res;
		}
	}
//	for(ll i=0;i<m;i++)
//	{
//		cout<<t[i].first<<' ';
//	}
//	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	string t;
	for(ll i=0;i<n;i++)
	{
		cin>>t;
		for(ll j=0;j<m;j++)
		{
			cin>>a[i][j]>>b[i][j]>>c[i][j];
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i==j) continue;
			ans=max(ans,solve(i,j));
		}
	}
	cout<<ans<<Endl;
	return 0;
}