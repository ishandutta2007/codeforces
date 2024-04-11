#include <cstdio>
#include <iostream>
using namespace std;
int p, y; 
bool inline check(int x) {
	for (int i = 2; i * i <= x && i <= p; i++)
		if(x % i == 0) return false;
	return true;
}
int main(){
	scanf("%d%d", &p, &y);
	for (int i = y; i > p; i--) {
		if(check(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}