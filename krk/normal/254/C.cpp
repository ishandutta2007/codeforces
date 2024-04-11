#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

char a[Maxn];
int alen;
char b[Maxn];
int blen;
int tims[Maxn][Maxl];
int freq[Maxl];
int res;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%s", a); alen = strlen(a);
	for (int i = 0; i < alen; i++)
		freq[a[i] - 'A']++;
	for (int i = alen - 1; i >= 0; i--) {
		for (int j = 0; j < Maxl; j++) tims[i][j] = tims[i + 1][j];
		tims[i][a[i] - 'A']++;
	}
	scanf("%s", b); blen = strlen(b);
	for (int i = 0; i < blen; i++)
		freq[b[i] - 'A']--;
	for (int i = 0; i < alen; i++)
		if (freq[a[i] - 'A'] > 0) {
			int j;
			for (j = 0; j < Maxl; j++)
				if (freq[j] < 0) break;
			if (j < a[i] - 'A' || tims[i + 1][a[i] - 'A'] < freq[a[i] - 'A']) {
				res++; freq[a[i] - 'A']--; freq[j]++;
				a[i] = 'A' + j;
			}
		}
	printf("%d\n", res);
	printf("%s\n", a);
	return 0;
}