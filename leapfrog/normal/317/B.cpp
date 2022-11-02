//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},DX=404;
int n,t,a[810][810];queue<pair<int,int> >q;
int main()
{
	read(n),read(t),a[DX][DX]=n,q.push(make_pair(0,0));
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop();
		int ad;if(a[x+DX][y+DX]<4) continue;else ad=a[x+DX][y+DX]/4,a[x+DX][y+DX]%=4;
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];a[tx+DX][ty+DX]+=ad;
			if(a[tx+DX][ty+DX]>=4) q.push(make_pair(tx,ty));
		}
	}
	for(int x,y;t--;) {read(x),read(y);if(x>=DX||x<=-DX||y>=DX||y<=-DX) puts("0");else printf("%d\n",a[x+DX][y+DX]);}
	return 0;
}