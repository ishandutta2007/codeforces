#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

const int N = 150005;

int n, b[N], t;

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1); t = 0;
		for (int i = 1; i <= n; i++) {
			//if (s[i] == 'o') {
				if ((i > 2 && s[i] == 'o' && s[i - 2] == 't' && s[i - 1] == 'w') && (i + 2 <= n && s[i + 2] == 'e' && s[i + 1] == 'n')) {
					s[i] = '#';
					b[++t] = i;
				} 
				if ((i > 2 && s[i] == 'o' && s[i - 2] == 't' && s[i - 1] == 'w')) {
					s[i - 1] = '#';
					b[++t] = i - 1;
				}
				if ((i + 2 <= n && s[i] == 'o' && s[i + 2] == 'e' && s[i + 1] == 'n')) {
					s[i + 1] = '#';
					b[++t] = i + 1;
				} 
			//}
			
		}
		printf("%d\n", t);
		for (int i = 1; i <= t; i++) printf("%d ", b[i]);
		puts("");
	}
	return 0;
}