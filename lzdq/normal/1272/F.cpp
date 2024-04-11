#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=205;
int n,m;
char s[MAXN],t[MAXN];
int f[MAXN][MAXN][MAXN],g[MAXN][MAXN][MAXN][4];
inline void upd(int a,int b,int c,int x,int y,int z,int w){
	a=min(a,n);
	b=min(b,m);
	if(a>max(n,m)||f[a][b][c]<=f[x][y][z]+1) return ;
	f[a][b][c]=f[x][y][z]+1;
	g[a][b][c][0]=x;
	g[a][b][c][1]=y;
	g[a][b][c][2]=z;
	g[a][b][c][3]=w;
}
void Print(int i,int j,int k){
	if(i+j+k==0) return ;
	Print(g[i][j][k][0],g[i][j][k][1],g[i][j][k][2]);
	if(g[i][j][k][3]) putchar(')');
	else putchar('(');
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%s%s",s,t);
	n=strlen(s);
	m=strlen(t);
	for(int i=0; i<n; i++)
		s[i]=(s[i]==')');
	for(int i=0; i<m; i++)
		t[i]=(t[i]==')');
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=m; j++){
			if(!s[i]&&!t[j]){
				for(int k=max(n,m); k>=0; k--){
					upd(i+1-s[i],j+1-t[j],k+1,i,j,k,0);
					if(k) upd(i+s[i],j+t[j],k-1,i,j,k,1);
				}
			}else for(int k=0; k<=max(n,m); k++){
				upd(i+1-s[i],j+1-t[j],k+1,i,j,k,0);
				if(k) upd(i+s[i],j+t[j],k-1,i,j,k,1);
			}
			//for(int k=0; k<=max(n,m); k++) printf("%d %d %d f %d\n",i,j,k,f[i][j][k]);
		}
	//printf("%d\n",f[n][m][0]);
	Print(n,m,0);
	puts("");
	return 0;
}