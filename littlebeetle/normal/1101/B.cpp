#include<cstdio>
const int N=500002;
char s[N];
int n,i,j,k,p;
int main(){
	scanf("%s",s+1);
	while(s[n+1])n++;
	for(i=1;s[i]&&s[i]!='[';i++);
	for(;s[i]&&s[i]!=':';i++);
	for(j=n;s[j]&&s[j]!=']';j--);
	for(;s[j]&&s[j]!=':';j--);
	if(i<j){
		for(k=i+1;k<j;k++)
			if(s[k]=='|')
				p++;
		printf("%d",p+4);
	}
	else
		printf("-1");
}