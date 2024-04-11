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
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;

void solve()
{
	int n0,n1,n2;
	cin>>n0>>n1>>n2;
	string s0,s2;
	if(n0)
	{
		for(int i=0;i<n0+1;i++)
		{
			s0+='0';
		}
	}
	if(n2)
	{
		for(int i=0;i<n2+1;i++)
		{
			s2+='1';
		}
	}
	if(n0 && n2)
	{
		n1--;
	}
	string s=s0+s2;
	if(!n0 && !n2)
	{
		n1--;
		s="01";
	}
	char now=(s.back());
	while(n1)
	{
		now='0'+'1'-now;
		s+=now;
		n1--;
	}
	cout<<s<<endl;
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