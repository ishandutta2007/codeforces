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
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
int a[105][105];
vector <int> r;
vector <int> c;

int main()
{	
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",a[i]+j);
		}
	}
	if(n<m)
	{
		for(int i=0;i<n;i++)
		{
			int minx=inf;
			for(int j=0;j<m;j++)
			{
				minx=min(minx,a[i][j]);
			}
			for(int j=0;j<m;j++)
			{
				a[i][j]-=minx;
			}
			for(int j=0;j<minx;j++)
			{
				r.push_back(i);
			}
		}
		for(int j=0;j<m;j++)
		{
			for(int i=1;i<n;i++)
			{
				if(a[i][j]!=a[0][j]) over("-1\n");
			}
			for(int i=0;i<a[0][j];i++)
			{
				c.push_back(j);
			}
		}
		cout<<r.size()+c.size()<<endl;
		for(int i=0;i<r.size();i++)
		{
			printf("row %d\n",r[i]+1);
		}
		for(int i=0;i<c.size();i++)
		{
			printf("col %d\n",c[i]+1);
		}
	}
	else
	{
		for(int j=0;j<m;j++)
		{
			int minx=inf;
			for(int i=0;i<n;i++)
			{
				minx=min(minx,a[i][j]);
			}
			for(int i=0;i<n;i++)
			{
				a[i][j]-=minx;
			}
			for(int i=0;i<minx;i++)
			{
				c.push_back(j);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(a[i][j]!=a[i][0]) over("-1\n");
			}
			for(int j=0;j<a[i][0];j++)
			{
				r.push_back(i);
			}
		}
		cout<<r.size()+c.size()<<endl;
		for(int i=0;i<r.size();i++)
		{
			printf("row %d\n",r[i]+1);
		}
		for(int i=0;i<c.size();i++)
		{
			printf("col %d\n",c[i]+1);
		}
	}
	return 0;
}