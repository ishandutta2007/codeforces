#include<cstdio>
const int N=100002;
int n,i,sum;
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n-10;i++)
		if(s[i]=='8')
			sum++;
	if(sum<=(n-11)/2)
		printf("NO");
	else
		printf("YES");
}