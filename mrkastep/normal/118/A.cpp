#include <stdio.h>
#include <algorithm>

int main(){
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	char c[101];
	int i;
	i=0;
	scanf("%s",&c);
	while(c[i]!='\0'){
		if((int)c[i]>64 && (int)c[i]<91){
			c[i]=c[i]+32;
		}
		if(c[i]!='a' && c[i]!='o' && c[i]!='i' && c[i]!='e' && c[i]!='u' && c[i]!='y'){
			printf(".%c",c[i]);
		}
		i++;
	}
}