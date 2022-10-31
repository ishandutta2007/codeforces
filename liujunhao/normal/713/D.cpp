#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1000
#define MAXLOG 9
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int Q;
short n,m,a[MAXN+10][MAXN+10],lg2[MAXN+10],f[MAXN+10][MAXN+10],st[MAXN+10][MAXN+10][MAXLOG+1][MAXLOG+1];
void read(){
	Read(n),Read(m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			Read(a[i][j]);
	for(i=2;i<=max(n,m);i++)
		lg2[i]=lg2[i>>1]+1;
}
inline int Get_st(int x1,int y1,int x2,int y2){
	int tx=lg2[x2-x1+1],ty=lg2[y2-y1+1];
	return max(max(st[x1][y1][tx][ty],st[x1][y2-(1<<ty)+1][tx][ty]),max(st[x2-(1<<tx)+1][y1][tx][ty],st[x2-(1<<tx)+1][y2-(1<<ty)+1][tx][ty]));
}
int Divide_Conqure(int x1,int y1,int x2,int y2,int l,int r){
	int mid((l+r)>>1);
	while(l<r){
		mid=(l+r+1)>>1;
		if(Get_st(x1+mid-1,y1+mid-1,x2,y2)>=mid)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
void solve(){
	int i,j,k,l;
	short x1,y1,x2,y2;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(a[i][j])
				f[i][j]=min(f[i][j-1],min(f[i-1][j],f[i-1][j-1]))+1;
			**st[i][j]=f[i][j];
		}
	for(k=1;k<=MAXLOG;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(i+(1<<k)-1>n)
					break;
				else
					*st[i][j][k]=max(*st[i][j][k-1],*st[i+(1<<(k-1))][j][k-1]);
	for(l=1;l<=MAXLOG;l++)
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(j+(1<<l)-1>m)
					break;
				else
					for(k=0;k<=MAXLOG;k++)
						if(i+(1<<k)-1>n)
							break;
						else
							st[i][j][k][l]=max(st[i][j][k][l-1],st[i][j+(1<<(l-1))][k][l-1]);
	Read(Q);
	while(Q--){
		Read(x1),Read(y1),Read(x2),Read(y2);
		printf("%d\n",Divide_Conqure(x1,y1,x2,y2,0,min(x2-x1,y2-y1)+1));
	}
}
int main()
{
	read();
	solve();
}