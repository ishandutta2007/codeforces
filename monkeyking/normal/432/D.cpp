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
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
const int mod=1e9+7;
using namespace std;
int n;
char c[100005];
ll e[100005];
ll hello[100005];
int s[100005];
int is[100005];
int ok[100005];
vector <int> res;

int gethello(int l,int r)
{
	l--;
	return ((hello[r]-(l>=0?hello[l]:0)*e[r-l])%mod+mod)%mod;
}

bool check(int x,int len)
{
	return (gethello(x,x+len-1)==gethello(0,len-1));
}

int getmax(int x)
{
	int l=0,r=n-x,mid;
	int ans=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(x,mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	e[0]=1;
	for(int i=1;i<=100000;i++)
	{
		e[i]=e[i-1]*107;
		e[i]%=mod;
	}
	scanf("%s",c);
	n=strlen(c);
	hello[0]=c[0];
	for(int i=0;i<n;i++)
	{
		hello[i]=hello[i-1]*107+c[i];
		hello[i]%=mod;
	}
	ll suf=0;
	for(int i=0;i<n;i++)
	{
		is[getmax(i)-1]++;
//		res+=s[getmax(i)];
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<getmax(i)<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<is[i]<<' ';
//	}
//	cout<<endl;
    // res.push_back(0);
    // cout<<res[0];
    // return 0;
	for(int i=0;i<n;i++)
	{
		suf=suf+c[n-i-1]*e[i];
		s[i]=(i?s[i-1]:0);
		suf%=mod;
		if(suf==hello[i]) s[i]++,res.push_back(i);
	}
	ok[n-1]=is[n-1];
	for(int i=n-2;i>=0;i--)
	{
		ok[i]=ok[i+1]+is[i];
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]+1<<' '<<ok[res[i]]<<endl;
	}
	return 0;
}