#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("INVALID"),0;
using namespace std;
const int N=1e3+5,dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
const char d[6]="DRLUX";
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x[N][N],y[N][N];
char ans[N][N];
inline bool in(int x,int y){return x<y?0<=x&&y<n:0<=y&&x<n;}
bool ok(int i1,int j1,int i2,int j2)
{
	return in(i2,j2)&&x[i1][j1]==x[i2][j2]&&y[i1][j1]==y[i2][j2];
}
void dfs(int i,int j,int f)
{
	if(ans[i][j])return;
	ans[i][j]=d[f^3];
	F(k,0,4)if(ok(i,j,i+dx[k],j+dy[k]))dfs(i+dx[k],j+dy[k],k);
}
int main()
{
	read(n);
	F(i,0,n)F(j,0,n)
	{
		read(x[i][j]);read(y[i][j]);
		if(~x[i][j])--x[i][j];
		if(~y[i][j])--y[i][j];
	}
	F(i,0,n)F(j,0,n)if(!~x[i][j])
	{
		bool ok=false;
		F(k,0,4)if(in(i+dx[k],j+dy[k])&&!~x[i+dx[k]][j+dy[k]])
			ans[i][j]=d[k],ok=true;
		if(!ok)fail;
	}
	F(i,0,n)F(j,0,n)if(x[i][j]==i&&y[i][j]==j)dfs(i,j,7);
	F(i,0,n)F(j,0,n)if(!ans[i][j])fail;
	puts("VALID");
	F(i,0,n)puts(ans[i]);
	return 0;
}