#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100005];

char fir[105], sec[105];

int lFir, lSec;
int n;

bool got() {
	int i;
	for (i = n - lSec; i >= 0; --i) {
		int j = 0;
		for (j = 0; j < lSec; ++j) {
			if (s[i + j] != sec[j])
				break;
		}
		if (j == lSec) break;
	}
	for (i = i - lFir; i >= 0; --i) {
		int j = 0;
		for (j = 0; j < lFir; ++j) {
			if (s[i + j] != fir[j])
				break;
		}
		if (j == lFir) break;

	}
	return (i >= 0);
}

int main() {
	scanf("%s%s%s", s, fir, sec);
	lFir = strlen(fir);
	lSec = strlen(sec);
	n = strlen(s);
	bool g1 = got();
	reverse(s, s + n);
	bool g2 = got();
	if (g1 && g2) printf("both\n");
	else if (g1) printf("forward\n");
	else if (g2) printf("backward\n");
	else printf("fantasy\n");
}