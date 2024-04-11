#include<cstdio>
int n,k,i,j,f;
char t[52];
int main(){
	scanf("%d%d%s",&n,&k,t+1);
	for(i=2;i<=n;i++){
		f=1;
		for(j=i;j<=n;j++)
			if(t[j]!=t[j-i+1]){
				f=0;
				break;
			}
		if(f)
			break;
	}
	j=i;
	for(i=1;i<=n;i++)
		printf("%c",t[i]);
	while(--k)
		for(i=n-j+2;i<=n;i++)
			printf("%c",t[i]);
	return 0;
}