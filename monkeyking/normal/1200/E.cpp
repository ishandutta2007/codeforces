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
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
const int mod=1001101021;
using namespace std;
int n;
string c[100005];
vector <int> h[100005];
int len[100005];
int e[1000005];
vector <int> hh;
string res;
int opti;

inline int gethash(vector <int> &h,int l,int r)
{
	if(r==0) return 0;
	opti=h[r-1]-1LL*(l?h[l-1]:0)*e[r-l]%mod;
	return (opti<0?opti+mod:opti);
}

inline void init(string &c,vector <int> &h)
{
	int len=c.size();
	h[0]=c[0];
	for(int i=1;i<len;i++)
	{
		h[i]=(1LL*h[i-1]*107+c[i])%mod;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n;
	hh.resize(1000005);
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		len[i]=c[i].size();
	}
	e[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		e[i]=(1LL*e[i-1]*107)%mod;
	}
	
	for(int i=0;i<n;i++)
	{
		h[i].resize(len[i]);
		init(c[i],h[i]);
//		h[i][0]=c[i][0];
//		for(int j=1;j<len[i];j++)
//		{
//			h[i][j]=(1LL*h[i-1][j]*107+c[i][j])%mod;
//		}
	}
	
	res=c[0];
	init(res,hh);
	int l,r,mid,ans;
	int length=res.size();
//	cout<<gethash(h[1],3,4)<<' '<<gethash(h[2],0,1)<<endl;
	for(int i=1;i<n;i++)
	{
		ans=0;
		l=0;
		r=min(len[i],length);
		for(mid=r;mid>=l;mid--)
		{
			if(gethash(hh,length-mid,length)==gethash(h[i],0,mid))
			{
				ans=mid;
				break;
			}
		}
		for(int j=ans;j<len[i];j++)
		{
			res.push_back(c[i][j]);
			hh[j-ans+length]=(1LL*hh[j-ans+length-1]*107+c[i][j])%mod;
		}
		length=res.size();
	}
	cout<<res<<endl;
	return 0;
}