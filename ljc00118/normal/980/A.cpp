#include<bits/stdc++.h>
using namespace std;

char c;
int a = 0, b = 0;

int main() {
	while(scanf("%c", &c) == 1) {
		if(c == '-') a++;
		if(c == 'o') b++;
	}
	if(b == 0) printf("YES");
	else if(a % b == 0) printf("YES");
	else printf("NO");
	return 0;
}