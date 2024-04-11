#include<cstdio>
#include<cstring>
const int MAXN=505;
int n,m;
char s[MAXN][MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
			scanf("%s",s[i]+1);
			if(i%3==1){
				for(int j=1; j<=m; j++)
					s[i][j]='X';
			}
		}
		for(int i=2; i+2<=n; i+=3){
			bool t=0;
			for(int j=1; j<=m; j++)
				if(s[i][j]=='X'||s[i+1][j]=='X'){
					s[i][j]=s[i+1][j]='X';
					t=1;
					break;
				}
			if(!t) s[i][1]=s[i+1][1]='X';
		}
		if(n%3==0){
			for(int i=1; i<=m; i++)
				if(s[n][i]=='X') s[n-1][i]='X';
		}
		for(int i=1; i<=n; i++)
			puts(s[i]+1);
	}
	return 0;
}