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
using namespace std;
int n,m;
int a[1005];
bool type[1005];
int l[1005];
int r[1005];

int main()
{
//	freopen("input.txt","r",stdin);
	int dyh=0;
	cin>>n>>m;
	n--;
	memset(a,-1,sizeof(a));
	for(int i=0;i<m;i++)
	{
		cin>>type[i]>>l[i]>>r[i];
		l[i]--;
		r[i]--;
	}
	for(int i=0;i<m;i++)
	{
		if(type[i]==1)
		{
			for(int j=l[i];j<r[i];j++)
			{
				a[j]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(type[i]==1) continue;
		bool flag=false;
		for(int j=l[i];j<r[i];j++)
		{
			if(a[j]==1 || a[j]==-1)
			{
				if(a[j]==-1) dyh++;
				a[j]=1;
				flag=true;
				break;
			}
		}
		if(flag==false) over("NO\n");
	}
	int k=1000000000/(dyh+2);
	int bds=dyh+1;
	int now=bds*k+1;
	cout<<"YES\n";
	cout<<now;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			bds--;
			now=bds*k+1;
		}
		else
		{
			now++;
		}
		cout<<' '<<now;
	}
	return 0;
}