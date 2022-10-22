#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 1000005;

char s[Maxn];
int slen;
int a, b;
bool ca[Maxn], cb[Maxn];
char A[Maxn], B[Maxn];
int alen, blen;

int main()
{
	scanf("%s", s); slen = strlen(s);
	if (slen == 1) { printf("NO\n"); return 0; }
	scanf("%d %d", &a, &b);
	int cur = 0;
	for (int i = 0; i < slen; i++) {
		cur = (10 * cur + s[i] - '0') % a;
		ca[i] = cur == 0;
	}
	cur = 0; int tns = 1;
	for (int i = slen - 1; i >= 0; i--) {
		cur = (tns * (s[i] - '0') + cur) % b;
		cb[i] = cur == 0 && s[i] != '0';
		tns = 10 * tns % b;
	}
	for (int i = 0; i + 1 < slen; i++)
		if (ca[i] && cb[i + 1]) {
			for (int j = 0; j <= i; j++)
				A[alen++] = s[j];
			A[alen] = '\0';
			for (int j = i + 1; j < slen; j++)
				B[blen++] = s[j];
			B[blen] = '\0';
			printf("YES\n");
			printf("%s\n", A);
			printf("%s\n", B);
			return 0;
		}
	printf("NO\n");
	return 0;
}