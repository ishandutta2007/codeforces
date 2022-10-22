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
using namespace std;
int n;
int c[2000005];
map <int,int> m;
int a[2000005];
int len;

void solve()
{
	scanf("%d",&n);
	m.clear();
	for(int i=0;i<n;i++)
	{
		scanf("%d",c+i);
		m[c[i]]++;
	}
	int mn=inf;
	len=0;
	for(auto x:m)
	{
		a[len++]=x.second;
		mn=min(mn,x.second);
	}
	int cnt;
	int res=inf;
	for(int s=mn+1;s>=1;s--)
	{
		cnt=0;
		bool ok=true;
		for(int i=0;i<len;i++)
		{
			int t=ceil(a[i],s);
			if(t<t*s-a[i])
			{
				ok=false;
				break;
			}
			cnt+=t;
		}
		if(ok)
		{
			res=min(res,cnt);
		}
	}
	printf("%d\n",res);
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