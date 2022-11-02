#include <stdio.h>
#include <algorithm>

int main(){
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	char c[101];
	int s,i,max;
	scanf("%s",&c);
	s=1;
	max=1;
	for(i=1;c[i]!='\0';i++){
		if(c[i]!=c[i-1]||c[i+1]=='\0'){
			if(c[i]==c[i-1]) s++;
			if(s>max) max=s;
			s=1;
		}
		else{
			s++;
		}
	}
	if(max>6) printf("YES");
	else printf("NO");
}