#include<cstdio>
const int N=10002;
char s[N];
int n,i,p;
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++){
		if(s[i]=='1')
			p++;
		else
			p--;
	}
	if(p!=0){
		printf("1\n%s",s+1);
		return 0;
	}
	printf("2\n%c ",s[1]);
	for(i=2;i<=n;i++)
		printf("%c",s[i]);
}