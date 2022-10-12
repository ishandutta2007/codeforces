#include<stdio.h>
char s[55];
bool ok(char x){
	if(x=='a')return true;
	if(x=='e')return true;
	if(x=='i')return true;
	if(x=='o')return true;
	if(x=='u')return true;
	if(x=='1')return true;
	if(x=='3')return true;
	if(x=='5')return true;
	if(x=='7')return true;
	if(x=='9')return true;
	return false;
}
int main(){
	scanf("%s",s);
	int res = 0;
	for(int i=0; s[i]; i++)
		if(ok(s[i]))
			res++;
	printf("%d\n",res);
	return 0;
}