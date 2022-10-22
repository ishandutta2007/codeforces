#include <cstdio>

using namespace std;

int n, k;
char num[200005];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf(" %c", &num[i]);
	if (n == 1) {
        if (k > 0) printf("0\n");
        else printf("%c\n", num[0]);
        return 0;
	}
	if (num[0] != '1' && k > 0) {
		num[0] = '1';
		k--;
	}
	for (int i = 1; i < n; i++) {
        if (num[i] != '0' && k > 0) {
            num[i] = '0';
            k--;
        }
	}
	printf("%s\n", num);
	return 0;
}