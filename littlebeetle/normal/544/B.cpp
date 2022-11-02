#include<cstdio>
const int N=1002;
int n,k,i,j;
char s[N][N];
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i%2==j%2&&k)
				s[i][j]='L',k--;
			else
				s[i][j]='S';
	if(k==0){
		printf("YES\n");
		for(i=1;i<=n;i++)
			printf("%s\n",s[i]+1);
	}
	else
		printf("NO\n");
}