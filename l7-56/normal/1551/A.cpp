#include<bits/stdc++.h>
using namespace std;

int n,t;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int c1,c2;
		c1 = c2 = n / 3;
		if(n % 3 == 1) c1++;
		if(n % 3 == 2) c2++;
		printf("%d %d\n", c1, c2);
	}
	return 0;
}