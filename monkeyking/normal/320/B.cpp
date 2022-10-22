#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
vector <int> vec[105];
int s=0;
bool visit[105];
pii a[105];
int n;

bool can(pii a,pii b)
{
	return(a.first>b.first && a.first<b.second || a.second>b.first && a.second<b.second); 
}

void dfs(int x)
{
//	cout<<endl<<x<<endl<<endl;;
	visit[x]=true;
	rep(vec[x].size())
	{
		if(!visit[vec[x][i]])
		{
			if(can(a[x],a[vec[x][i]])) dfs(vec[x][i]);
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int x,y,z;
	cin>>n;
	rep(n)
	{
		cin>>x>>y>>z;
		if(x==1)
		{
			a[s++]=make_pair<int,int>(y,z);
			rep(s)
			{
				if(can(a[s-1],a[i])) vec[s-1].push_back(i);
				if(can(a[i],a[s-1])) vec[i].push_back(s-1);
			}
		}
		else 
		{
			fill(visit,visit+s,0);
			dfs(--y);
//			rep(s)
//			{
//				cout<<visit[i]<<' ';
//			}
//			cout<<endl;
			cout<<(visit[--z]?"YES\n":"NO\n");
		}
//		cout<<"\nbegin:\n";
//		rep(s)
//		{
//			repj(vec[i].size())
//			{
//				cout<<vec[i][j]<<' ';
//			}
//			cout<<endl;
//		} 
//		cout<<"end:\n";
	}
	return 0;
}