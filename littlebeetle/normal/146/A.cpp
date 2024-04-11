#include<cstdio>
const int N=10002;
int n,i,sum;
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		if(s[i]!='4'&&s[i]!='7'){
			printf("NO");
			return 0;
		}
	for(i=1;i<=n/2;i++)
		sum+=s[i];
	for(;i<=n;i++)
		sum-=s[i];
	printf("%s",sum==0?"YES":"NO");
	//while(1);
}