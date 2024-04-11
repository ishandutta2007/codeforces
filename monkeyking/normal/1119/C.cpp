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
#include <chrono>
#include <time.h>
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
int a[505][505];
int b[505][505];

int main()
{
//	srand();
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				a[i][j]^=1;
				a[i+1][j]^=1;
				a[i][j+1]^=1;
				a[i+1][j+1]^=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				cout<<"No\n";
				return 0;
			}
		}
	}
	cout<<"Yes\n";
//	for(int i=0;i<n;i++)
//	{
//		vector <int> v;
//		for(int j=0;j<m;j++)
//		{
//			v.push_back(0);
//		}
//		vec.push_back(v);
//	}
//	for(int t=0;t<10000;t++)
//	{
//		int sx=rand(0,n-1);
//		int sy=rand(0,m-1);
//		int ex=rand(0,n-1);
//		int ey=rand(0,m-1);
////		if(ex!=sx+1 || ey!=sy+1) continue;
////		cout<<sx<<' '<<sy<<' '<<ex<<' '<<ey<<endl;
//		if(sx==ex || sy==ey) continue;
//		vec[sx][sy]^=1;
//		vec[sx][ey]^=1;
//		vec[ex][sy]^=1;
//		vec[ex][ey]^=1;
//		::m[vec]=true;
//	}
//	for(auto x:(::m))
//	{
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//			{
//				cout<<x.first[i][j]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
	return 0;
}