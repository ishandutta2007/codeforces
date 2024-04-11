#include<cstdio>
const int N=1000002;
int n,i,top;
char s[N],t[N];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++){
		while(top%2&&s[i]==t[top])
			t[top]=0,top--;
		t[++top]=s[i];
	}
	if(top%2)
		t[top]=0,top--;
	printf("%d\n%s",n-top,t+1);
}