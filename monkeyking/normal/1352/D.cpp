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
int n;
int a[1005];

void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	int steps=0;
	int s1=0,s2=0;
	int preeaten=0;
	while(l<=r)
	{
		steps++;
		int s=0;
		if(steps&1)
		{
			while(l<=r)
			{
				s+=a[l];
				s1+=a[l++];
				if(s>preeaten)
				{
					preeaten=s;
					break;
				}
			}
		}
		else
		{
			while(l<=r)
			{
				s+=a[r];
				s2+=a[r--];
				if(s>preeaten)
				{
					preeaten=s;
					break;
				}
			}
		}
	}
	cout<<steps<<' '<<s1<<' '<<s2<<endl;
}

int main()
{
// 	freopen("input.txt","r",stdin);
	quickcin;
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}