#include<cstdio>
const int N=100;
int n,i,j;
char s[N][N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(s[i][j]=='.'&&s[i+1][j-1]=='.'&&s[i+1][j]=='.'&&s[i+1][j+1]=='.'&&s[i+2][j]=='.'){
				s[i][j]='#';
				s[i+1][j-1]='#';
				s[i+1][j]='#';
				s[i+1][j+1]='#';
				s[i+2][j]='#';
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(s[i][j]=='.'){
				printf("NO");
				return 0;
			}
	printf("YES");
		}