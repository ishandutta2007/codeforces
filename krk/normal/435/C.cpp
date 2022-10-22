#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1015;
const int nil = 1005;

int n;
char B[2 * Maxn][Maxn];
int mn = nil, mx = nil;

int main()
{
	fill((char*)B, (char*)B + (2 * Maxn) * Maxn, ' ');
	scanf("%d", &n);
	int curr = nil, curc = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (i % 2 == 0) {
			while (a--) {
				B[curr][curc] = '/';
				mn = min(mn, curr); mx = max(mx, curr);
				curr--; curc++;
			} 
			curr++;
		} else {
			while (a--) {
				B[curr][curc] = '\\';
				mn = min(mn, curr); mx = max(mx, curr);
				curr++; curc++;
			}
			curr--;
		}
	}
	for (int i = mn; i <= mx; i++) {
		for (int j = 0; j < curc; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}
	return 0;
}