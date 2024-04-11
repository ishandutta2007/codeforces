#include<bits/stdc++.h>
bool ispal(char*s,int ls){
	for(int i=0,j=ls-1; i<j; i++,j--)
		if(s[i] != s[j])
			return false;
	return true;
}
int main(){
	char s[99];
	scanf("%s",s);
	int ls = strlen(s);
	for(int i=0; i<ls; i++){
		char tmp = s[i];
		for(char c = 'a'; c <= 'z'; c++)if(c!=tmp){
			s[i] = c;
			if(ispal(s,ls)){
				puts("YES");
				return 0;
			}
		}
		s[i] = tmp;
	}
	puts("NO");
	return 0;
}