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
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
char c[300005];
vector <int> vec[300005];
vector <int> ap[300005];
int f[600005];
int cost[600005];
int mustchoose[600005];
int choose[600005];

int find(int x)
{
	return (f[x]==x?x:f[x]=find(f[x]));
}

void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rand()&1)
	{
		f[y]=x;
		cost[x]+=cost[y];
		mustchoose[x]|=mustchoose[y];
	}
	else
	{
		f[x]=y;
		cost[y]+=cost[x];
		mustchoose[y]|=mustchoose[x];
	}
}

int main() 
{
// 	freopen("input.txt","r",stdin);
//	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	scanf("%s",c);
	int len,x;
	for(int i=0;i<m;i++)
	{
		cin>>len;
		while(len--)
		{
			cin>>x;
			x--;
			vec[i].push_back(x);
			ap[x].push_back(i);
		}
	}
	for(int i=0;i<2*m;i++)
	{
		f[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		cost[i]=1;
		choose[i]=0;
		choose[i+m]=true;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(ap[i].size()==1)
		{
			int a=ap[i][0];
			if(c[i]=='0')
			{
				if(choose[find(a+m)])
				{
					res-=cost[find(a+m)];
					res+=cost[find(a)];
					choose[find(a)]=true;
					choose[find(a+m)]=false;
				}
				mustchoose[find(a)]=true;
			}
			else
			{
				if(choose[find(a)])
				{
					res-=cost[find(a)];
					res+=cost[find(a+m)];
					choose[find(a)]=false;
					choose[find(a+m)]=true;
				}
				mustchoose[find(a+m)]=true;
			}
		}
		else if(ap[i].size()==2)
		{
			int a=ap[i][0],b=ap[i][1];
			if((c[i]=='1' && find(a)!=find(b)) || (c[i]=='0' && find(a)!=find(b+m)))
			{
				if(choose[find(a)]) res-=cost[find(a)];else res-=cost[find(a+m)];
				if(choose[find(b)]) res-=cost[find(b)];else res-=cost[find(b+m)];
				if(c[i]=='1')
				{
					merge(a,b);
					merge(a+m,b+m);
				}
				else
				{
					merge(a,b+m);
					merge(b,a+m);
				}
				assert(!(mustchoose[find(a)] && mustchoose[find(a+m)]));
				assert(!(mustchoose[find(b)] && mustchoose[find(b+m)]));
				bool ca;
				if(mustchoose[find(a)])
				{
					ca=true;
				}
				else if(mustchoose[find(a+m)])
				{
					ca=false;
				}
				else
				{
					ca=(cost[find(a)]<cost[find(a+m)]?1:0);
				}
				if(ca)
				{
					res+=cost[find(a)];
					choose[find(a)]=true;
					choose[find(a+m)]=false;
				}
				else
				{
					res+=cost[find(a+m)];
					choose[find(a+m)]=true;
					choose[find(a)]=false;
				}
			}
		}
		cout<<res<<endl;
	}
	
	return 0;
}