#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200005;
int n, q, L[N][26], R[N][26];
char s[N];

int main() {
	scanf("%s%d", s + 1, &q);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) L[i][j] = L[i - 1][j];
		L[i][s[i] - 'a'] = i;
	}

	memset(R, 0x3f, sizeof R);
	for (int i = n; i; i--) {
		for (int j = 0; j < 26; j++) R[i][j] = R[i + 1][j];
		R[i][s[i] - 'a'] = i;
	}

	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		if (l == r || s[l] != s[r]) puts("Yes");
		else {
		    int cnt = 0;
		    for (int i = 0; i < 26; i++)
		        if (R[l][i] <= r) cnt++;
		   	puts(cnt >= 3 ? "Yes" : "No");
		}
	}
	return 0;
}