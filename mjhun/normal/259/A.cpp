#include <bits/stdc++.h>
using namespace std;

int main(){
	char s[16];
	for(int i=0;i<8;++i){
		scanf("%s",s);
		for(int j=0;j<7;++j)if(s[j]==s[j+1])return puts("NO"),0;
	}
	puts("YES");
	return 0;
}