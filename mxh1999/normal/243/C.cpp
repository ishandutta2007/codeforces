//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 4010
int n;
int bo[maxn][maxn];
int numx[maxn],cx;
int numy[maxn],cy;
int posx[maxn];
int posy[maxn];
int lx[maxn],rx[maxn];
int ly[maxn],ry[maxn];
int cnt_x;
int cnt_y;
int x[maxn],y[maxn],tot;
queue<pair<int,int> >	Q;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int main()
{
	read(n);
	int _x=0,_y=0;
	cx=1,cy=1;
	tot=1;
	for (int i=1;i<=n;i++)
	{
		char ch=getchar();
		int op;
		while (ch!='L' && ch!='R' && ch!='U' && ch!='D')	ch=getchar();
		read(op);
		if (ch=='L')
		{
			_x-=op;
			numx[++cx]=_x;
		}	else
		if (ch=='R')
		{
			_x+=op;
			numx[++cx]=_x;
		}	else
		if (ch=='U')
		{
			_y+=op;
			numy[++cy]=_y;
		}	else
		if (ch=='D')
		{
			_y-=op;
			numy[++cy]=_y;
		}
		tot++;
		x[tot]=_x,y[tot]=_y;
	}
	sort(numx+1,numx+cx+1);
	cx=unique(numx+1,numx+cx+1)-(numx+1);
	sort(numy+1,numy+cy+1);
	cy=unique(numy+1,numy+cy+1)-(numy+1);
	cnt_x=2;
	lx[1]=rx[1]=numx[1]-1;
	lx[2]=rx[2]=numx[1];
	posx[1]=2;
	for (int i=2;i<=cx;i++)
	{
		if (numx[i]!=numx[i-1]+1)
		{
			cnt_x++;
			lx[cnt_x]=numx[i-1]+1;
			rx[cnt_x]=numx[i]-1;
		}
		cnt_x++;
		lx[cnt_x]=numx[i];
		rx[cnt_x]=numx[i];
		posx[i]=cnt_x;
	}
	cnt_x++;
	lx[cnt_x]=rx[cnt_x]=numx[cx]+1;
	cnt_y=2;
	ly[1]=ry[1]=numy[1]-1;
	ly[2]=ry[2]=numy[1];
	posy[1]=2;
	for (int i=2;i<=cy;i++)
	{
		if (numy[i]!=numy[i-1]+1)
		{
			cnt_y++;
			ly[cnt_y]=numy[i-1]+1;
			ry[cnt_y]=numy[i]-1;
		}
		cnt_y++;
		ly[cnt_y]=numy[i];
		ry[cnt_y]=numy[i];
		posy[i]=cnt_y;
	}
	cnt_y++;
	ly[cnt_y]=ry[cnt_y]=numy[cy]+1;
	for (int i=1;i<=tot;i++)
	{
		int _x=lower_bound(numx+1,numx+cx+1,x[i])-numx;
		int _y=lower_bound(numy+1,numy+cy+1,y[i])-numy;
		x[i]=posx[_x],y[i]=posy[_y];
	}
	bo[x[1]][y[1]]=1;
	for (int i=2;i<=tot;i++)
	{
		if (x[i]==x[i-1])
		{
			int _y=y[i],_y2=y[i-1];
			if (_y>_y2)	swap(_y,_y2);
			for (int j=_y;j<=_y2;j++)	bo[x[i]][j]=1;
		}	else
		{
			int _x=x[i],_x2=x[i-1];
			if (_x>_x2)	swap(_x,_x2);
			for (int j=_x;j<=_x2;j++)	bo[j][y[i]]=1;
		}
	}
	bo[1][1]=-1;
	Q.push(mp(1,1));
	while (!Q.empty())
	{
		int x=Q.front().fi,y=Q.front().se;
		Q.pop();
		for (int i=0;i<4;i++)
		{
			_x=x+dx[i];
			_y=y+dy[i];
			if (_x<=cnt_x && _x>=1 && _y<=cnt_y && _y>=1)
			if (bo[_x][_y]==0)
			{
				bo[_x][_y]=-1;
				Q.push(mp(_x,_y));
			}
		}
	}
	ll mjy=0;
	for (int i=1;i<=cnt_x;i++)
		for (int j=1;j<=cnt_y;j++)
		if (bo[i][j]!=-1)
			mjy+=1LL*(rx[i]-lx[i]+1)*(ry[j]-ly[j]+1);
	printf("%I64d\n",mjy);
	return 0;
}