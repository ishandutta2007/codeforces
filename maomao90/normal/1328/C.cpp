#include <cstdio>
#include <cstring>

using namespace std;

int t;
int n;
char x[50005];
char a[50005], b[50005];
bool diff;

int main() {
	scanf("%d", &t);
	while (t--) {
        diff = false;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
		scanf("%d", &n);
		scanf(" %s", x);
		for (int i = 0; i < n; i++) {
			if (diff) {
				a[i] = '0';
				b[i] = x[i];
			} else {
				if (x[i] == '0') a[i] = '0', b[i] = '0';
				else if (x[i] == '1') {
					a[i] = '1', b[i] = '0';
					diff = true;
				} else a[i] = '1', b[i] = '1';
			}
		}
		printf("%s\n%s\n", a, b);
	}
	return 0;
}