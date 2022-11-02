#include<cstdio>
const int N=200002;
int n,i,g[10];
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=9;i++)
		scanf("%d",g+i);
	for(i=1;i<=n;i++)
		s[i]-=48;
	for(i=1;i<=n;i++)
		if(g[s[i]]>s[i])
			break;
	while(i<=n&&g[s[i]]>=s[i]){
		s[i]=g[s[i]];
		i++;
	}
	for(i=1;i<=n;i++)
		printf("%d",s[i]);
	return 0;
}