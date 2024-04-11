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
int a[1000005];
vector<vector<int> > vec;
bool visit[1000005];
vector <int> now;
int temp[1000005];
int res[1000005];
int pos[1000005];
vector <pair<int,int> > tbs;

void dfs(int x)
{
	now.push_back(x);
	if(visit[pos[x]]) return;
	visit[pos[x]]=true;
	dfs(pos[x]);
}

void makeodd(int id)
{
	vector <int> temp;
	int len=vec[id].size();
	temp.resize(len);
	for(int i=0;i<len;i+=2)
	{
		temp[i]=vec[id][i/2];
	}
	for(int i=1;i<len;i+=2)
	{
		temp[i]=vec[id][len/2+i/2+1];
	}
	for(int i=0;i<len;i++)
	{
		res[temp[(i+1)%len]]=temp[i];
	}
}

void makeven(int id1,int id2)
{
	vector <int> temp;
	int len=vec[id1].size();
//	for(int i=0;i<len;i++)
//	{
//		cout<<vec[id2][i]<<' ';
//	}
//	cout<<endl;
	temp.resize(len*2);
	for(int i=0;i<len;i++)
	{
		temp[i*2]=vec[id1][i];
		temp[i*2+1]=vec[id2][i];
	}
//	for(int i=0;i<len*2;i++)
//	{
//		cout<<temp[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<len*2;i++)
	{
		res[temp[(i+1)%(len*2)]]=temp[i];
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
	for(int i=0;i<n;i++)
	{
		if(visit[i]) continue;
		visit[i]=true;
		now.clear();
		dfs(i);
		vec.push_back(now);
	}
	int even=0;
	for(int i=0;i<vec.size();i++)
	{
		if(((int)vec[i].size())%2==0)
		{
			tbs.push_back(mp(vec[i].size(),i));
		}
	}
	sort(all(tbs));
	if(even&1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<tbs.size();i+=2)
	{
		if(tbs[i].first!=tbs[i+1].first)
		{
			over(-1);
		}
		else
		{
			makeven(tbs[i].second,tbs[i+1].second);
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		if(((int)(vec[i].size()))%2)
		{
			makeodd(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",res[i]+1);
	}
	cout<<endl;
	return 0;
}