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
bool use[50005];

struct pos
{
	int x,y,z;
	int id;
	void input()
	{
		scanf("%d%d%d",&x,&y,&z);
	}
}point[50005];

bool operator < (const pos &a,const pos &b)
{
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
	if(a.z!=b.z) return a.z<b.z;
	return a.id<b.id;
}

bool contain(const pos &a,const pos &b,const pos &c)
{
//	cout<<a.x<<' '<<b.x<<' '<<c.x<<endl;
//	cout<<(min(a.x,b.x)<=c.x && max(a.x,b.x)>=c.x)<<endl;
	return (min(a.x,b.x)<=c.x && max(a.x,b.x)>=c.x && min(a.y,b.y)<=c.y && max(a.y,b.y)>=c.y && min(a.z,b.z)<=c.z && max(a.z,b.z)>=c.z); 
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		point[i].input();
		point[i].id=i+1;
	}
//	cout<<contain(point[1],point[2],point[4])<<endl;
	sort(point,point+n);
	pos ans;
	bool flag=false;
	int k;
	for(int i=0;i<n;i++)
	{
		if(use[i]) continue;
		use[i]=true;
		flag=false;
		for(int j=i+1;j<n;j++)
		{
			if(use[j]) continue;
			if(flag==false) ans=point[j],k=j,flag=true;
			else
			{
				if(contain(point[i],ans,point[j])) ans=point[j],k=j;
			}
		}
		use[k]=true;
		cout<<point[i].id<<' '<<ans.id<<endl;
	}
	return 0;
}