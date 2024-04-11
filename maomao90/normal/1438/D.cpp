#include <bits/stdc++.h>
using namespace std;

#define FI first
#define SE second
typedef tuple <int, int, int> iii;

int n;
int a[100005];
int sum;
map<int, vector<int> > cnt;
vector <iii> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]].push_back(i);
		sum ^= a[i];
	}
	if (n % 2 == 0) {
		if (sum != 0) {
			printf("NO\n");
			return 0;
		}
		n--;
	} 	
	printf("YES\n");
	printf("%d\n", n - 2);
	int i;
	for (i = 1; i + 2 <= n; i += 2) {
		printf("%d %d %d\n", i, i + 1, i + 2);
	}
	for (i -= 4; i >= 1; i -= 2) {
		printf("%d %d %d\n", i, i + 1, i + 2);
	}
	return 0;
}