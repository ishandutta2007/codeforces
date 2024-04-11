#include<cstdio>
const int N=300002;
int n,i;
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<n;i++)
		if(s[i]>s[i+1]){
			printf("YES\n%d %d",i,i+1);
			return 0;
		}
	printf("NO");
}