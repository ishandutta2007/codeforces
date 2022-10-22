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
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int k;
string s;
int len[1000005];
int words;

bool check(int width)
{
	int res=0;
	int chars=inf;
	for(int i=0;i<words;i++)
	{
		if(len[i]>width) return false;
	}
	for(int i=0;i<words;i++)
	{
		if(chars+len[i]>width)
		{
			res++;
			chars=len[i];
		}
		else
		{
			chars+=len[i];
		}
	}
	return (res<=k);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>k;
	getline(cin,s);
	getline(cin,s);
	for(int i=0,j=0;i<s.size();i=j)
	{
		for(j=i;j<=s.size();j++)
		{
			if(j==s.size() || s[j]==' ' || s[j]=='-' || s[j]=='\n')
			{
				len[words++]=j-i;
				j++;
				break;
			}
		}
	}
	for(int i=0;i<words-1;i++)
	{
		len[i]++;
	}
	int l=1,r=s.size(),mid,res=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<res<<endl;
	return 0;
}