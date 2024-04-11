#include<bits/stdc++.h>
#define N 259
#define M 300009
using namespace std;

int m,n,A,B,C,head,tail,h[M][2],d[N][N],ans[N][N]; char s[N][N];
void add(int x,int y){
	if (x>0 && x<=m && y>0 && y<=n){
		if (d[x][y]==-1 && s[x][y]!='*'){
			d[x][y]=C; h[++tail][0]=x; h[tail][1]=y;
		}
	}
}
int main(){
	scanf("%d%d%d%d",&m,&n,&A,&B);
	int i,j,x,y;
	memset(d,-1,sizeof(d));
	for (i=1; i<=m; i++) scanf("%s",s[i]+1);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++) if (s[i][j]>='A' && s[i][j]<='Z'){
			head=0; tail=1;
			h[1][0]=i; h[1][1]=j; d[i][j]=(s[i][j]-'A'+1)*A;
			while (head<tail){
				x=h[++head][0]; y=h[head][1];
				ans[x][y]+=d[x][y]; C=d[x][y]>>1;
				if (!C) continue;
				add(x-1,y); add(x+1,y); add(x,y-1); add(x,y+1);
			}
			while (tail){
				d[h[tail][0]][h[tail][1]]=-1; tail--;
			}
		}
	for (i=1,tail=0; i<=m; i++)
		for (j=1; j<=n; j++) if (ans[i][j]>B) tail++;
	cout<<tail<<endl;
	return 0;
}