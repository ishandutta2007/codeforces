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
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int n;
int a[1005];
int s[1005];

int findmin()
{
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++)
	{
		s[a[i]]++;
	}
	for(int i=0;i<=n;i++)
	{
		if(s[i]==0) return i;
	}
}

void solve()
{
	cin>>n;
	set <int> squ;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		squ.insert(a[i]);
	}
	vector <int> res;
	for(int i=0;i<n;i++)
	{
		int t=findmin();
		if(t>=n)
		{
			bool ok=true;
			for(int j=0;j<n;j++)
			{
				if(a[j]!=j)
				{
					a[j]=findmin();
					res.push_back(j);
					ok=false;
					break;
				}
			}
			if(ok==true) break;
		}
		t=findmin();
		a[t]=t;
		res.push_back(t);
	}
	cout<<res.size()<<endl;
	for(auto x:res)
	{
		cout<<x+1<<' ';
	}
	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}