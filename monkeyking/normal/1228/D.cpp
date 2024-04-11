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
vector <int> vec[100005];
vector <int> zl[3];
int col[100005];
int sum[3];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		sort(all(vec[i]));
	}
	int k=1;
	zl[0]=vec[0];
	col[0]=0;
	sum[0]=1;
	for(int i=1;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<k;j++)
		{
			if(vec[i]==zl[j])
			{
				col[i]=j;
				flag=true;
				sum[j]++;
				break;
			}
		}
		if(flag==false)
		{
			if(k==3)
			{
				over(-1);
			}
			else
			{
				zl[k++]=vec[i];
				col[i]=k-1;
				sum[k-1]=1;
			}
		}
	}
	if(k!=3)
	{
		over(-1);
	}
//	cout<<sum[0]<<' '<<sum[1]<<' '<<sum[2]<<endl;
	if((sum[0]*sum[1]+sum[1]*sum[2]+sum[2]*sum[0])!=m) over(-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",col[i]+1);
	}
	return 0;
}