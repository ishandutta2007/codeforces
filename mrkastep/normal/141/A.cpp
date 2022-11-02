#include <stdio.h>
#include <algorithm>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	char s1[101],s2[101],s[101];
	scanf("%s%s%s",&s1,&s2,&s);
	std::sort(s,s+strlen(s));
	strcat(s1,s2);
	std::sort(s1,s1+strlen(s1));
	if(strcmp(s1,s)==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}