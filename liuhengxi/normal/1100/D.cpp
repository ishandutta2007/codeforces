#include<cstdio>
#include<cstdlib>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,n=999,m=666,half=499;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int x,y,xx[N],yy[N],cnt[2][2],tx,ty;
bool is[N][N];
void move(int nx,int ny)
{
	if(is[nx][ny])
	{
		nx=x;
	}
	printf("%d %d\n",nx+1,ny+1);fflush(stdout);
	int k,X,Y;read(k),read(X),read(Y);
	if(k<=0)exit(0);
	x=nx,y=ny;
	--k,--X,--Y;
	is[xx[k]][yy[k]]=false;
	is[xx[k]=X][yy[k]=Y]=true;
}
int main()
{
	--read(x),--read(y);
	F(i,0,m)--read(xx[i]),--read(yy[i]),is[xx[i]][yy[i]]=true;
	while(x!=half||y!=half)move(x+(x!=half)*(x<half?1:-1),y+(y!=half)*(y<half?1:-1));
	F(i,0,m)++cnt[xx[i]>half][yy[i]>half];
	if(cnt[0][1]<cnt[tx][ty])tx=0,ty=1;
	if(cnt[1][0]<cnt[tx][ty])tx=1,ty=0;
	if(cnt[1][1]<cnt[tx][ty])tx=1,ty=1;
	while(true)move(x+(tx?-1:1),y+(ty?-1:1));
	return 0;
}