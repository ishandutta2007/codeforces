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
typedef unsigned long long ull;
using namespace std;
map <char,int> dx;
map <char,int> dy;
int gx,gy;

int cal(int a,int b)
{
	return abs(gx-a)+abs(gy-b);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,sx,sy;
	cin>>n>>sx>>sy>>gx>>gy;
	if(sx==gx && sy==gy)
	{
		cout<<0<<endl;
		return 0;
	}
	string c;
	cin>>c;
	int nowx=sx,nowy=sy;
	dx['S']=0;
	dx['E']=1;
	dx['W']=-1;
	dx['N']=0;
	dy['S']=-1;
	dy['E']=0;
	dy['W']=0;
	dy['N']=1;
	int tx,ty;
	for(int i=0;i<n;i++)
	{
//		cout<<nowx<<'-'<<nowy<<endl;
//		cout<<dx[c[i]]<<' '<<dy[c[i]]<<endl;
		tx=nowx+dx[c[i]];
		ty=nowy+dy[c[i]];
		if(tx==gx && ty==gy)
		{
			cout<<i+1<<endl;
			return 0;
		}
//		cout<<cal(nowx,nowy)<<Endl;;
		if(cal(tx,ty)>cal(nowx,nowy)) continue;
//		cout<<c[i]<<' '<<tx<<'-'<<ty<<endl;
		nowx=tx;
		nowy=ty;
	}
	cout<<"-1\n";
	return 0;
}