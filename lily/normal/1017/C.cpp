/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)

int n;
int ans[233333];
int main() {
	cin >> n;
	int B = 1;
	for (int i = 1; i <= n; i++) {
		ans[i] = (n + i - 1) / i + i;
		if (ans[i] < ans[B]) B = i;
	}
	for (int i = 0; i * B < n; i++) {
		if (((i + 1) * B) > n)  {
			for (int j = 1; j <= B; j++) {
				if (i * B + j > n) break;
				ans[i * B + j] = j;
			}
			break;
		}
		else {
			for (int j = 1; j <= B; j++) {
				ans[i * B + j] = n - B * (i + 1) + j;
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);	
	return 0;
}