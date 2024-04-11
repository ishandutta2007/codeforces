#include<cstdio>
inline int minn(int a,int b){
	if(a<b) return a;
	return b;
}
const int MAXN=105,MAXM=1e6+5,INF=0x3fffffff;
int n,m;
char s[MAXN];
int w[MAXN][MAXN];
int top,stk[MAXM];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			if(i==j) w[i][j]=0;
			else if(s[j]=='0')w[i][j]=INF;
			else w[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k) continue;
				w[i][j]=minn(w[i][j],w[i][k]+w[k][j]);
			}
	scanf("%d",&m);
	top=0;
	while(m--){
		int a;
		scanf("%d",&a);
		while(top>1&&w[stk[top-1]][stk[top]]+w[stk[top]][a]==w[stk[top-1]][a])
			top--;
		stk[++top]=a;
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++){
		printf("%d",stk[i]);
		if(i==top) puts("");
		else putchar(' ');
	}
	return 0;
}