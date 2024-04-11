#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int num[4]={0,1,2,3}; 
int n,m;

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int x,y,gx,gy;
	cin>>n>>m;
	char map[n+2][m+2];
	rep(n)
	{
		scanf("%s",map[i]);
		for(int j=0;j<m;j++)
		{
			if(map[i][j]=='S')
			{
				x=i;
				y=j;
			}
			if(map[i][j]=='E')
			{
				gx=i;
				gy=j;
			}
		}
	}
	string c;
	cin>>c;
	int len=c.size();
	int nx,ny,dire;
	int ans=0;
	do
	{
		nx=x;
		ny=y;
		for(int i=0;i<len;i++)
		{
			dire=c[i]-'0';
			nx+=dx[num[dire]];
			ny+=dy[num[dire]];
//			cout<<nx<<'-'<<ny<<"  ";
			if(out(nx,ny)) break;
			if(map[nx][ny]=='#') break;
			if(nx==gx && ny==gy)
			{
			    ans++;
			    break;
			}
		}
//		cout<<endl;
	}while(next_permutation(num,num+4));
	cout<<ans<<endl;
	return 0;
}