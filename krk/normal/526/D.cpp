#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int n, k;
char str[Maxn];
int slen;
int Z[Maxn];
int delt[Maxn];
char res[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", str); slen = strlen(str);
	int l = -1, r = -1;
	for (int i = 1; i < slen; i++) {
		if (i <= r) Z[i] = min(Z[i - l], r - i + 1);
		while (i + Z[i] < slen && str[Z[i]] == str[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > r) { l = i; r = i + Z[i] - 1; }
	}
	for (int l = 1; k * l <= slen; l++) {
		bool ok = true;
		for (int j = 1; j < k && ok; j++)
			ok = Z[j * l] >= l;
		if (ok) {
			delt[k * l - 1]++;
			int fin = min(slen, k * l + min(Z[k * l], l));
			delt[fin]--;
		}
	}
	int cur = 0;
	for (int i = 0; i < slen; i++) {
		cur += delt[i];
		res[i] = cur? '1': '0';
	}
	res[slen] = '\0';
	printf("%s\n", res);
	return 0;
}