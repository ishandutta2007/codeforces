#include<bits/stdc++.h>
char s1[33],s2[33];
int main(){
	scanf("%s%s",s1,s2);
	int pnt = 0;
	for(int i=0; s1[i]; i+=2)
		if(s1[i] != s2[i]){
			if(
			s1[i] == '[' && s2[i] == '8' ||
			s1[i] == '(' && s2[i] == '[' ||
			s1[i] == '8' && s2[i] == '('
			  )pnt++;
			else
			pnt--;
		}
	if(pnt > 0)puts("TEAM 2 WINS");else
	if(pnt < 0)puts("TEAM 1 WINS");else
		puts("TIE");
	return 0;
}