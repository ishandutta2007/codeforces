#include <cstdio>
using namespace std;

const int Maxn = 305;
const int Maxk = 1000005;

int n;
int a[Maxn];
char s[Maxk];
int slen;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ind = 0;
	while (ind + 1 < n) {
		if (a[ind] == 0) { s[slen++] = 'R'; ind++; }
		else {
			a[ind]--;
			s[slen++] = 'P'; s[slen++] = 'R'; s[slen++] = 'L';
		}
	}
	while (a[ind]) {
		a[ind]--;
		s[slen++] = 'P'; s[slen++] = 'L'; s[slen++] = 'R';
	}
	s[slen] = '\0';
	printf("%s\n", s);
	return 0;
}