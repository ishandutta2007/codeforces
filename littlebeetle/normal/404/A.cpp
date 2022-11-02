#include<cstdio>
const int N=303;
int n,i,j;
char s[N][N],a,b;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	a=s[1][1];
	b=s[1][2];
	if(a==b){
		printf("NO");
		return 0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j||i+j==n+1){
				if(s[i][j]!=a){
					printf("NO");
					return 0;
				}
			}
			else{
				if(s[i][j]!=b){
					printf("NO");
					return 0;
				}
			}
	printf("YES");
}