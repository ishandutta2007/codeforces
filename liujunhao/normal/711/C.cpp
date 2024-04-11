#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
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
#define MAXN 100
int n,m,k,p[MAXN+10][MAXN+10],c[MAXN+10];
long long f[MAXN+10][MAXN+10][MAXN+10],ans=0x3f3f3f3f3f3f3f3fll;
int main()
{
	Read(n),Read(m),Read(k);
	int i,j,l,q;
	for(i=1;i<=n;i++)
		Read(c[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			Read(p[i][j]);
	memset(f,0x3f,sizeof f);
	if(c[1])
		f[1][1][c[1]]=0;
	else
		for(i=1;i<=m;i++)
			f[1][1][i]=p[1][i];
	for(i=2;i<=n;i++)
		for(j=1;j<=k;j++){
			if(c[i]){
				for(q=1;q<=m;q++)
					f[i][j][c[i]]=min(f[i-1][j-(q!=c[i])][q],f[i][j][c[i]]);
			}
			else{
				for(l=1;l<=m;l++)
					for(q=1;q<=m;q++)
						f[i][j][l]=min(f[i-1][j-(l!=q)][q]+p[i][l],f[i][j][l]);
			}
		}
	for(i=1;i<=m;i++)
		ans=min(ans,f[n][k][i]);
	if(ans==0x3f3f3f3f3f3f3f3fll)
		puts("-1");
	else
		printf("%I64d\n",ans);
}