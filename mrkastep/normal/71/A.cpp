#include <stdio.h>
#include <algorithm>

int main(){
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	char c[100][101];
	int n,i,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&c[i]);
		l=strlen(c[i]);
		if(l>10){
			printf("%c%d%c\n",c[i][0],l-2,c[i][l-1]);
		}
		else{
			printf("%s\n",c[i]);
		}
	}
}