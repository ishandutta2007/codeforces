#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,cnt;bool nw[N],vs[2][N];
bool chk(int x) {return vs[1][x] && (vs[0][x-1] || vs[0][x] || vs[0][x+1]);}
int f(int x) {return chk(x-1)+chk(x)+chk(x+1);}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x,y,t;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		if(x==1)
		{
			if(vs[0][y]) t=f(y),vs[0][y]=0,cnt+=f(y)-t;
			else t=f(y),vs[0][y]=1,cnt+=f(y)-t;
		}
		else
		{
			if(vs[1][y]) t=chk(y),vs[1][y]=0,cnt+=chk(y)-t;
			else t=chk(y),vs[1][y]=1,cnt+=chk(y)-t;
		}puts(cnt?"No":"Yes");
	}return 0;
}