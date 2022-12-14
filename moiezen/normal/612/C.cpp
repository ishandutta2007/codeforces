#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
int code(char x){
	if(x=='{') return 0;
	if(x=='}') return 1;
	if(x=='[') return 2;
	if(x==']') return 3;
	if(x=='(') return 4;
	if(x==')') return 5;
	if(x=='<') return 6;
	if(x=='>') return 7;
}
char s[1000005];
int stack[1000005],top=0;
int n,i,j,k,flag=1,ans=0;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		if(code(s[i])&1){
			if(top==0){
				flag=0;
				break;	
			}
			if(stack[top]!=code(s[i])-1) ans++;
			top--;
		}
		else{
			top++;
			stack[top]=code(s[i]);
		}
	}
	if(top) flag=0;
	if(flag) printf("%d",ans);
	else printf("Impossible");
	return 0;
}