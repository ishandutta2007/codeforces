#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;scanf("%d",&n);
	if(n<4){puts("NO");return 0;}
	puts("YES");
	if(n%2){
		for(int i=6;i<n;i+=2){
			printf("%d - %d = %d\n",i+1,i,1);
			puts("1 * 1 = 1");
		}
		puts("5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24");
	}
	else {
		for(int i=5;i<n;i+=2){
			printf("%d - %d = %d\n",i+1,i,1);
			puts("1 * 1 = 1");
		}
		puts("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24");
	}
	return 0;
}