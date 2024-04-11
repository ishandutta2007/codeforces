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
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int par[300005];
int n,q;
int beat[300005];

int find(int x)
{
	return (par[x]==x?x:par[x]=find(par[x]));
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	int l,r,win;
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
	}
//	par[2]=2+1;
//	par[1]=1+1;
//	cout<<find(1)<<endl;
//	cout<<par[1]<<endl;
//	return 0;
	while(q--)
	{
		cin>>l>>r>>win;
		l--;
		r--;
		win--;
		for(int i=find(l);i<=r;i=find(i))
		{
			
//			cout<<i+1<<' '<<find(i+1)<<endl;
			if(i==win)
			{
				i++;
				if(i>r) break;
				continue;
			}
			par[i]=i+1;
			beat[i]=win+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<beat[i]<<' ';
	}
	cout<<endl;
	return 0;
}