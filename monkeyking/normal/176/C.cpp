#include <iostream>
#include <algorithm>
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
int n,m,x1,y1,x2,y2;

int mabs(int x)
{
	if(x<0) return -x;else return x;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>x1>>y1>>x2>>y2;
	x1--;y1--;
	x2--;y2--;
	int x=mabs(x1-x2);
	int y=mabs(y1-y2);
	if(x==0 || y==0)
	{
		int t=max(x,y);
		if(t<=4) over("First") else over("Second");
	}
	else if(x==1 || y==1)
	{
		int t=max(x,y);
		if(t<=4) over("First") else over("Second");
	}
	else if(x==2 || y==2)
	{
		int t=max(x,y);
		if(t<=4) over("First") else over("Second");
	}
	else if(x==3 && y==3) over("First");
	over("Second");
	return 0;
}