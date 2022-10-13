#include<stdio.h>
int main(){
	char s[9];
	scanf("%s",s);
	int r=0,i;
	for(i=0; s[i]; i++){
		if(s[i]=='A')r++;else
		if(s[i]>='2' && s[i]<='9')r+=s[i]-'0';else{
			r+=10;
			i++;
		}
	}
	printf("%d\n",r);
	return 0;
}