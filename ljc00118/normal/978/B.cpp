#include<bits/stdc++.h>
using namespace std;

char c[110];
int n;
int ans = 0;

int main() {
	scanf("%d", &n);
	int tmp = 0;
	scanf("%s", c);
	for(int i = 0; i < n; i++) {
		if(c[i] == 'x') tmp++;
		else tmp = 0;
		if(tmp == 3) {
			ans++;
			tmp--;
		}
	}
	printf("%d", ans);
	return 0;
}