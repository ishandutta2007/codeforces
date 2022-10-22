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
int a[55][55];
int rev;
//int ans[]={0,1,0,1,0,1};
int kk;

int query(int sx,int sy,int ex,int ey)
{
	cout<<"? "<<sx+1<<' '<<sy+1<<' '<<ex+1<<' '<<ey+1<<endl;
	fflush(stdout);
	int t;
//	if(kk<6) return ans[kk++];
	cin>>t;
	if(t==-1) exit(0);
	return t;
}

void print()
{
	cout<<"!\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(rev && ((i+j)&1)) cout<<!a[i][j];else cout<<a[i][j];
//			cout<<a[i][j];
		}
		cout<<endl;
	}
	fflush(stdout);
	exit(0);
}

void check23(int x,int y)
{
	if(x+1>=n || y+2>=n) return;
	if(a[x][y]==a[x+1][y+2] && (a[x+1][y]==a[x+1][y+1] || a[x][y+1]==a[x+1][y+1] || a[x][y+1]==a[x][y+2]))
	{
		if(query(x,y,x+1,y+2))
		{
			rev=false;
			print();
		}
		else
		{
			rev=true;
			print();
		}
	}
}

void check32(int x,int y)
{
	if(x+2>=n || y+1>=n) return;
	if(a[x][y]==a[x+2][y+1] && (a[x+1][y]==a[x+2][y] || a[x+1][y]==a[x+1][y+1] || a[x][y+1]==a[x+1][y+1]))
	{
		if(query(x,y,x+2,y+1))
		{
			rev=false;
			print();
		}
		else
		{
			rev=true;
			print();
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	a[0][0]=1;
	a[n-1][n-1]=0;
	for(int i=0;i<n;i++)
	{
		if(i&1)
		{
			a[i][1]=1^query(i-1,0,i,1)^a[i-1][0];
			for(int j=3;j<n;j+=2)
			{
				a[i][j]=1^query(i,j-2,i,j)^a[i][j-2];
			}
		}
		else
		{
			if(i) a[i][0]=1^query(i-2,0,i,0)^a[i-2][0];
			for(int j=2;j<n;j+=2)
			{
				if(i==n-1 && j==n-1) continue;
				a[i][j]=1^query(i,j-2,i,j)^a[i][j-2];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!(i&1))
		{
			if(i) a[i][1]=1^query(i-1,0,i,1)^a[i-1][0];
			for(int j=3;j<n;j+=2)
			{
				a[i][j]=1^query(i,j-2,i,j)^a[i][j-2];
			}
		}
		else
		{
			a[i][2]=1^query(i-1,1,i,2)^a[i-1][1];
			for(int j=4;j<n;j+=2)
			{
				if(i==n-1 && j==n-1) continue;
				a[i][j]=1^query(i,j-2,i,j)^a[i][j-2];
			}
			a[i][0]=1^query(i,0,i,2)^a[i][2];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			check23(i,j);
			check32(i,j);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=(i&1)^1;j<n;j+=2)
		{
			a[i][j]^=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			check23(i,j);
			check32(i,j);
		}
	}
	assert(false);
	return 0;
}