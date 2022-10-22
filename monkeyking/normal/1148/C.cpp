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
int n;
int a[300005];
vector <pair<int,int> >vec;
int pos[300005];

inline bool inR(int x)
{
	return x>=(n/2);
}

inline bool inL(int x)
{
	return x<(n/2);
}

void MSwap(int i,int j)
{
	vec.push_back(mp(i+1,j+1));
	swap(pos[a[i]],pos[a[j]]);
	swap(a[i],a[j]);
}

void DoSwap(int x)
{
	if(x==pos[x]) return;
	int i=x,j=pos[x];
	if(inL(x) && inL(pos[x]))
	{
		MSwap(i,n-1);
		MSwap(n-1,j);
		MSwap(i,n-1);
		return;
	}
	if(inR(x) && inR(pos[x]))
	{
		MSwap(i,0);
		MSwap(0,j);
		MSwap(0,i);
		return;
	}
	if(inL(x) && inR(pos[x]))
	{
		MSwap(0,j);
		MSwap(n-1,i);
		MSwap(0,n-1);
		MSwap(0,j);
		MSwap(n-1,i);
		return;
	}
	if(inR(x) && inL(pos[x]))
	{
		MSwap(0,i);
		MSwap(pos[x],j);
		MSwap(0,n-1);
		MSwap(0,i);
		MSwap(j,n-1);
	}
	
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
		pos[a[i]]=i;
	}
	if(inR(pos[0]))
	{
		MSwap(0,pos[0]);
	}
	else
	{
		if(pos[0]!=0)
		{
			MSwap(n-1,pos[0]);
			MSwap(0,n-1);
		}
	}
	if(inL(pos[n-1]))
	{
		MSwap(pos[n-1],n-1);
	}
	else
	{
		if(pos[n-1]!=n-1)
		{
			MSwap(pos[n-1],1);
			MSwap(1,n-1);
		}
	}
	for(int i=1;i<n-1;i++)
	{
		DoSwap(i);
	}
	cout<<vec.size()<<endl;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i].first>vec[i].second) swap(vec[i].first,vec[i].second);
		printf("%d %d\n",vec[i].first,vec[i].second);
	}
	return 0;
}