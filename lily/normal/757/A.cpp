/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

const char S[] = "Bulbasaur";

char s[100005];

int cnt[256], hh[256], ans = 10247445;

int main() {
	scanf("%s", s );
	for (int i = strlen(s) - 1; i > -1; i--) cnt[s[i]]++;
	for (int i = strlen(S) - 1; i > -1; i--) hh[S[i]]++;
	for (int i = 'z'; i >= 'A'; i--) {
		if (hh[i]) ans = min(ans, cnt[i] / hh[i]);
	}
	printf("%d\n", ans);
	return 0;
}