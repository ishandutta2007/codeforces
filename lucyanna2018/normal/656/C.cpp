#include<stdio.h>
#include<string.h>
char s[99];
int to(int x){
	if(x>='A' && x<='Z')return x-'A'+1;
	if(x>='a' && x<='z')return x-'a'+1;
	if(x>='0' && x<='9')return x-'0';
	return 0;
}
int main(){
	int res = 0;
	scanf("%s",s+1);
	int L=strlen(s+1);
	for(int i=1; i<=L; i++){
		int x = s[i];
		bool op1 = '@' < x;
		bool op2 = '[' > x;
		bool op3 = '`' < x;
		bool op4 = '{' > x;
		int A = (int)(op1 && op2) * to(x);
		int B = (int)(op3 && op4) * to(x);
		//printf("%c %d\n",x,A-B);
		res += A-B;
	}
	printf("%d\n",res);
	return 0;
}