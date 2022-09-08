#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

char c[N];
int n;
char ans[2];
int maxn = 0;

int main() {
	scanf("%d %s", &n, c);
	for(int i = 'A'; i <= 'Z'; i++) {
		for(int j = 'A'; j <= 'Z'; j++) {
			int tmp = 0;
			for(int k = 0; k < n - 1; k++) {
				if(c[k] == i && c[k + 1] == j) tmp++;
			}
			if(tmp > maxn) {
				maxn = tmp;
				ans[0] = i;
				ans[1] = j;
			}
		}
	}
	printf("%c%c", ans[0], ans[1]);
	return 0;
}