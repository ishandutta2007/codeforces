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
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
int p[200005];
int f[200005];

int find(int x)
{
	return (x==f[x]?x:f[x]=find(f[x]));
}

int add(int x,int y)
{
	x=find(x);
	y=find(y);
	if(rand()&1) f[x]=y;else f[y]=x;
}

void init()
{
	for(int i=0;i<n;i++)
	{
		f[i]=i;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	init();
	for(int i=0;i<n;i++)
	{
		scanf("%d",p+i);
		p[i]--;
	}
	int root=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i]==i)
		{
			root=i;
			break;
		}
	}
	int ans=0;
	if(root==-1)
	{
		for(int i=0;i<n;i++)
		{
			if(find(i)==find(p[i]))
			{
	//			cout<<i<<' '<<p[i]<<endl;
				root=i;
				p[i]=i;
				ans++;
				break;
			}
			else
			{
				add(i,p[i]);
			}
		}
	}
	init();
	for(int i=0;i<n;i++)
	{
		if(i==root) continue;
		if(find(i)==find(p[i]))
		{
//			cout<<i<<' '<<p[i]<<endl;
			ans++;
			p[i]=root;
			add(i,root);
		}
		else
		{
			add(i,p[i]);
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]+1<<' ';
	}
	cout<<endl;
	return 0;
}