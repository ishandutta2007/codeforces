#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum = 0, _;
	char s[99];
	for(scanf("%d",&_); _--;){
		scanf("%s",s);
		switch(*s){
		case 'T': sum += 4; break;
		case 'C': sum += 6; break;
		case 'O': sum += 8; break;
		case 'D': sum += 12; break;
		case 'I': sum += 20; break;
		}
	}
	printf("%d\n",sum);
	return 0;
}