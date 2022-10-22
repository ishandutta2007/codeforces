#include <cstdio>

using namespace std;

int n, t;
char seq[200005];
int dec;

int main() {
	scanf("%d%d",&n, &t);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &seq[i]);
		if (seq[i] == '.') dec = i + 1;
	}
	int last = n - 1;
	for (int i = dec; i < n; i++) {
		int cur = seq[i] - '0';
		if (cur >= 5 && t > 0) {
			last = i == dec ? i - 2 : i - 1;
			seq[last]++;
			t--;
			for (int j = i - 1; j >= dec; j--) {
				int temp = seq[j] - '0';
				if (temp >= 5 && t > 0) {
					seq[j == dec ? j - 2 : j - 1]++;
					last = j == dec ? j - 2 : j - 1;
					t--;
				} else {
					break;
				}
			}
			break;
		}
	}
	for (int i = dec - 2; i >= 0; i--) {
		if (i != 0 && seq[i] - '0' == 10) {
			seq[i] = '0';
			seq[i - 1]++;
		} else break;
	}
	if (seq[0] - '0' == 10) {
		printf("1");
		seq[0] = '0';
	}
	for (int i = 0; i <= last; i++) {
		printf("%c", seq[i]);
	}
	printf("\n");
	return 0;
}