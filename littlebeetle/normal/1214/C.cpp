#include<cstdio>
const int N=200002;
char s[N];
int n,i,p,k;
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='(')
			p++;
		else
			p--;
	if(p){
		printf("No");
		return 0;
	}
	for(i=1;i<=n;i++){
		if(s[i]=='(')
			p++;
		else
			p--;
		if(p<0)
			p++,k++;
	}
	if(k>1)
		printf("No");
	else
		printf("Yes");
}