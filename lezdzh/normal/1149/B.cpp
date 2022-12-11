#include<cstdio>
#include<vector>
using namespace std;

int n,m;
char s[100002];
int a[3][100001],z[26][100002];
vector<int>g[1001][1001];
int gt(int u1,int u2,int u3){
	if(!u1&&!u2&&!u3)return 0;
	return min(min(u1?z[a[0][u1]][min(n+1,g[u1-1][u2][u3]+1)]:2e9,
		u2?z[a[1][u2]][min(n+1,g[u1][u2-1][u3]+1)]:2e9),
		u3?z[a[2][u3]][min(n+1,g[u1][u2][u3-1]+1)]:2e9);
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<26;i++)
		z[i][n+1]=2e9;
	for(int i=n;i;i--)
		for(int j=0;j<26;j++)
			z[j][i]=s[i]==j+'a'?i:z[j][i+1];
	g[0][0].push_back(0);
	for(int i=1;i<=m;i++){
		char o;
		scanf(" %c",&o);
		if(o=='+'){
			int x;
			char cc;
			scanf("%d %c",&x,&cc);
			a[x-1][++a[x-1][0]]=cc-'a';
			for(int i=0;i<=a[0][0];i++)if(x!=1||i==a[0][0])
				for(int j=0;j<=a[1][0];j++)if(x!=2||j==a[1][0])
					for(int k=0;k<=a[2][0];k++)if(x!=3||k==a[2][0]){
						while(g[i][j].size()<=k+1)
							g[i][j].push_back(2e9);
						g[i][j][k]=gt(i,j,k);
					}
		}
		else{
			int x;
			scanf("%d",&x);
			a[x-1][0]--;
		}
		if(g[a[0][0]][a[1][0]][a[2][0]]!=2e9)
			printf("YES\n");
		else printf("NO\n");
	}
}