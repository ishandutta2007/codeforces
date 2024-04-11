#include<cstdio>
char s[10002];///
int n,i;
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<n;i++)
		if(s[i]!=s[i+1]){
			printf("YES\n%c%c",s[i],s[i+1]);
			return 0;
		}
	printf("NO");
}