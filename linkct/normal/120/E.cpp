#include <cstdio>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testcase, t;
	scanf("%d", &testcase);
	while(testcase --){
		scanf("%d", &t);
		printf("%d\n", (t & 1) ^ 1);
	}
	return 0;
}