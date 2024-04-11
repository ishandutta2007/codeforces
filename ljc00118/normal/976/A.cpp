#include<bits/stdc++.h>
using namespace std;

int n, x = 0, y = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		char c = getchar();
		while(c != '0' && c != '1') c = getchar();
		if(c == '1') x++;
		else y++;
	}
	if(x) printf("1");
	for(int i = 1; i <= y; i++) printf("0");
	return 0;
}