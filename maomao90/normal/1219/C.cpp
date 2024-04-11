#include <bits/stdc++.h>
using namespace std;

int l;
char a[300005];
char res[300005];

int main() {
	scanf("%d", &l);
	scanf(" %s", a);
	int n = strlen(a);
	if (l > n) {
		if (l == 1) printf("0\n");
		else {
			printf("1");
			for (int i = 0; i < l - 1; i++) printf("0");
			printf("\n");
		}
		return 0;
	}
	int pt = 0;
	while (pt < n) {
		for (int i = 0; i < l; i++) {
			res[pt++] = a[i];
		}
	}
	if (strlen(res) > n) {
		for (int i = 0; i < l; i++) a[i] = '0';
		a[0] = '1';
		int pt = 0;
		while (pt < n) {
			for (int i = 0; i < l; i++) {
				res[pt++] = a[i];
			}
		}
	} else if (strcmp(res, a) > 0) {
	} else {
		bool all9 = true;
		for (int i = l - 1; i >= 0; i--) {
			if (a[i] != '9') {
				a[i]++;
				all9 = false;
				break;
			} else a[i] = '0';
		}
		if (all9) {
			for (int i = 0; i < l; i++) a[i] = '0';
			a[0] = '1';
			int pt = 0;
			while (pt <= n) {
				for (int i = 0; i < l; i++) {
					res[pt++] = a[i];
				}
			}
		} else {
			int pt = 0;
			while (pt < n) {
				for (int i = 0; i < l; i++) {
					res[pt++] = a[i];
				}
			}
		}
	}
	printf("%s\n", res);
	return 0;
}