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
ll n,m;
vector <ll> vec[100005];
ll len[100005];
vector <ll> v;
vector <ll> sum[100005];
int num[100005];

bool compare(int x,int y)
{
	return len[x]>len[y];
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	ll x,y;
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		x--;
		vec[x].push_back(y);
		len[x]++;
	}
	for(ll i=0;i<m;i++)
	{
//		cout<<i<<endl;
		sort(all(vec[i]));
		reverse(all(vec[i]));
		bool fuck=true;
		if(vec[i].size()) if(vec[i][0]>0) sum[i].push_back(vec[i][0]),fuck=false;
		if(fuck==false)
		{
			for(ll j=1;j<vec[i].size();j++)
			{
				if(sum[i][j-1]+vec[i][j]<=0) break;
				sum[i].push_back(sum[i][j-1]+vec[i][j]);
			}
		}
//		cout<<sum[0].size()<<endl;
		len[i]=sum[i].size();
	}
//	cout<<len[0];
	for(int i=0;i<m;i++)
	{
		num[i]=i;
	}
	sort(num,num+m,compare);
	int last=m;
	ll maxn=0;
	ll res;
//	for(int i=0;i<m;i++)
//	{
//		cout<<num[i]<<' ';
//	}
//	cout<<endl;
	for(int l=1;l<=n;l++)
	{
		res=0;
		for(int i=0;i<last;i++)
		{
//			cout<<len[0]<<endl;
			if(len[num[i]]<l)
			{
				last=i;
				break;
			}
			res+=sum[num[i]][l-1];
		}
		maxn=max(maxn,res);
	}
	cout<<maxn<<endl;
//	for(ll i=0;i<m;i++)
//	{
//		v.push_back(len[i]);
//	}
//	sort(all(v));
//	ll l=unique(all(v))-v.begin();
//	ll maxn=0;
//	for(ll i=0;i<l;i++)
//	{
//		if(v[i]==0) continue;
//		ll res=0;
//		for(ll j=0;j<n;j++)
//		{
//			if(len[j]<v[i]) continue;
//			res+=sum[j][v[i]-1];
//		}
//		maxn=max(maxn,res);
//	}
//	cout<<maxn<<endl;
	return 0;
}