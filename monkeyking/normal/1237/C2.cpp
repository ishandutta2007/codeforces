#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <assert.h>
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
map<int,map<int,set<pair<int,int> > > >vec;
map<int,set <int> >who;
set <int> havex;
int x[50005];
int y[50005];
int z[50005];

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

int del(int nx,int ny,int nz)
{
	int px=*havex.lower_bound(nx);
//	int px=lower_bound(x,x+n,nx)-x;
//	cout<<px<<endl;
	set <int> :: iterator it;
	it=who[px].lower_bound(ny);
	if(it==who[px].end())
	{
		it--;
//		it=who[px].upper_bound(ny);
	}
	int py=*it;
	
//	cout<<py<<endl;
	set<pair<int,int> > :: iterator it2=vec[px][py].lower_bound(mp(nz,0));
	if(it2==vec[px][py].end())
	{
		it2--;
//		it2=vec[px][py].upper_bound(mp(nz,inf));
	}
	pair<int,int> pz=*it2;
//	cout<<i+1<<' '<<pz.second<<endl;
	use[pz.second-1]=true;
	vec[px][py].erase(pz);
	if(vec[px][py].size()==0)
	{
		vec[px].erase(py);
		who[px].erase(py);
	}
	if(who[px].size()==0)
	{
		havex.erase(px);
	}
	return pz.second;
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
	int lx=0,ly=0,lz=0;
	set <int> empty;
	for(int i=0;i<n;i++)
	{
		havex.insert(point[i].x);
		if(lx==0 || x[lx-1]!=point[i].x)
		{
			x[lx++]=point[i].x;
			ly=0;
			lz=0;
			y[ly++]=point[i].y;
			z[lz++]=point[i].z;
			who[point[i].x].insert(point[i].y);
			vec[point[i].x][point[i].y].insert(mp(point[i].z,point[i].id));
			continue;
		}
		if(ly==0 || y[ly-1]!=point[i].y)
		{
			lz=0;
			y[ly++]=point[i].y;
			z[lz++]=point[i].z;
			who[point[i].x].insert(point[i].y);
			vec[point[i].x][point[i].y].insert(mp(point[i].z,point[i].id));
			continue;
		}
		if(lz==0 || z[lz-1]!=point[i].z)
		{
			lz=0;
			z[lz++]=point[i].z;
			vec[point[i].x][y[ly-1]].insert(mp(point[i].z,point[i].id));
			continue;
		}
		assert(false);
	}
	for(int i=0;i<n;i++)
	{
		if(use[point[i].id-1]) continue;
//		use[i]=true;
		int nx=point[i].x;
		int ny=point[i].y;
		int nz=point[i].z;
		del(nx,ny,nz);
		int tbd=del(nx,ny,nz);
		cout<<point[i].id<<' '<<tbd<<endl;
//		for(int k=0;k<n;k++)
//		{
//			cout<<use[k]<<' ';
//		}
//		cout<<endl;
	}
//	pos ans;
//	bool flag=false;
//	int k;
//	for(int i=0;i<n;i++)
//	{
//		if(use[i]) continue;
//		use[i]=true;
//		flag=false;
//		for(int j=i+1;j<n;j++)
//		{
//			if(use[j]) continue;
//			if(flag==false) ans=point[j],k=j,flag=true;
//			else
//			{
//				if(contain(point[i],ans,point[j])) ans=point[j],k=j;
//			}
//		}
//		use[k]=true;
//		cout<<point[i].id<<' '<<ans.id<<endl;
//	}
	return 0;
}