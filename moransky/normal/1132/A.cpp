#include <cstdio>
#include <iostream>
using namespace std;
int c1, c2, c3, c4; 
int main(){
	scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
	if(c1 == c4 && c4 >= min(c3, 1)) puts("1");
	else puts("0");
	return 0;
}