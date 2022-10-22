#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=405,INF=0x3fffffff;
int n,m;
char s1[MAXN],s2[MAXN];
int nx[MAXN][26];
int f[MAXN][MAXN];
void Calc(char *s,char *t,int a,int b){
	for(int i=0; i<=a; i++)
		for(int j=0; j<=b; j++){
			if(!i&&!j) continue;
			f[i][j]=INF;
			if(i&&f[i-1][j]<INF) f[i][j]=min(f[i][j],nx[f[i-1][j]][s[i]-'a']);
			if(j&&f[i][j-1]<INF) f[i][j]=min(f[i][j],nx[f[i][j-1]][t[j]-'a']);
		}
	return ;
}
int main(){
	//freopen("E.in","r",stdin);
	int t; scanf("%d",&t);
	while(t--){
		scanf("%s%s",s1+1,s2+1);
		n=strlen(s1+1);
		m=strlen(s2+1);
		for(int i=0; i<=n; i++){
			for(int j=0; j<26; j++){
				nx[i][j]=INF;
				for(int k=i+1;k<=n;k++)
					if(s1[k]=='a'+j){
						nx[i][j]=k;
						break;
					}
			}
		}
		bool ans=0;
		for(int i=1; i<=m; i++){
			//[1,i]  [i+1,m]
			Calc(s2,s2+i,i,m-i);
			if(f[i][m-i]<INF){
				//printf("find %d\n",i);
				ans=1;
				break;
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}