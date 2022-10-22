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
int n,q;
set <pair<int,int> > squ;
bool st[2][100005];
const int dx[]={-1,-1,-1,1,1,1};
const int dy[]={-1,0,1,-1,0,1};

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=2 || y>=n);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		x--;
		y--;
		if(st[x][y])
		{
			st[x][y]=0;
			for(int i=0;i<6;i++)
			{
				int nx=x+dx[i],ny=y+dy[i];
				if(out(nx,ny)) continue;
				if(squ.count(mp(nx*n+ny,x*n+y)))
				{
					squ.erase(mp(nx*n+ny,x*n+y));
				}
				if(squ.count(mp(x*n+y,nx*n+ny)))
				{
					squ.erase(mp(x*n+y,nx*n+ny));
				}
			}
		}
		else
		{
			st[x][y]=1;
			for(int i=0;i<6;i++)
			{
				int nx=x+dx[i],ny=y+dy[i];
				if(out(nx,ny)) continue;
				if(st[nx][ny]) squ.insert(mp(nx*n+ny,x*n+y));
				if(st[nx][ny]) squ.insert(mp(x*n+y,nx*n+ny));
			}
		}
		if(squ.size())
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}