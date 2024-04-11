#include<cstdio>
#include<algorithm>
#define MAXN 200000
#define MAXLOG 17
int n,m,fa[MAXN+10][MAXLOG+1],dep[MAXN+10];
using namespace std;
void Read(int &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int d1,d2;
int LCA(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	int i;
	for(i=MAXLOG;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(i=MAXLOG;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return *fa[x];
}
int len;
int main()
{
	dep[1]=1;
	d1=d2=1;
	Read(n);
	int i,j;
	for(i=2;i<=n;i++){
		Read(*fa[i]);
		dep[i]=dep[*fa[i]]+1;
		for(j=1;j<=MAXLOG;j++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
		int dep1=dep[d1]+dep[i]-2*dep[LCA(d1,i)],dep2=dep[d2]+dep[i]-2*dep[LCA(d2,i)];
		if(dep1<=len&&dep2<=len)
			printf("%d ",len);
		else if(dep1>dep2)
			printf("%d ",dep1),d2=i,len=dep1;
		else
			printf("%d ",dep2),d1=i,len=dep2;
	}
}