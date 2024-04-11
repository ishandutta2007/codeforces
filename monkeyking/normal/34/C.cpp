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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
bool visit[1005];

int main()
{
//	freopen("input.txt","r",stdin);
	int a[105];
	int n=0;
	char c=',';
	while(c==',')
	{
		cin>>a[n++];
		c=getchar();
	}
	rep(n)
	{
		visit[a[i]]=true;
	}
	int l[1005],r[1005],k=0;
	for(int i=1;i<1002;i++)
	{
		if(!visit[i-1] && visit[i])
		{
			l[k]=i;
			r[k]=i;
		}
		else if(visit[i] && visit[i-1])
		{
			r[k]++;
		}
		else if(visit[i-1])
		{
			k++;
		}
	}
	for(int i=0;i<k;i++)
	{
		if(r[i]==l[i]) cout<<r[i];else cout<<l[i]<<'-'<<r[i];
		if(i==k-1) cout<<'\n';else cout<<',';
	}
	return 0;
}