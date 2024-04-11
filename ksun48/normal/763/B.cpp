#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	printf("YES\n");
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		scanf("%d", &x1);
		scanf("%d", &x2);
		scanf("%d", &y1);
		scanf("%d", &y2);
		int d = 1;
		if(x1 % 2 != 0) d++;
		if(x2 % 2 != 0) d+=2;
		printf("%d\n", d);
	}
}