#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 200005;

char s[N];

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int cnt = 0, b = 0, sumB = 0;
		for (int i = n; i; i--) {
			if (s[i] == 'B') sumB++, b++;
			else {
				if (b) cnt++, b--;
			}
		}	
		printf("%d\n", n - cnt * 2 - ((sumB - cnt) / 2 * 2));
	}	
	return 0;
}