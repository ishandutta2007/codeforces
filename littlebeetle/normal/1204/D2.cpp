#include<cstdio>
const int N=1000002;
char s[N];
int n,i,st[N],top;
int main(){
	scanf("%s",s+1);
	for(n=0;s[n+1];n++);
	for(i=1;i<=n;i++)
		if(!top)
			st[++top]=i;
		else{
			if(s[i]==48&&s[st[top]]==49)
				top--;
			else
				st[++top]=i;
		}
	for(i=1;i<=top;i++)
		s[st[i]]=48;
	printf("%s",s+1);
	//while(1);
}