#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int sum, ave;
vector <int> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) sum += i;
	ave = sum / 2;
	int cur = 0;
	for (int i = n; i > 0; i--)
		if (cur + i <= ave) {
			cur += i;
			ans.push_back(i);
		}
    printf("%d\n", sum % 2);
	printf("%d ", (int) ans.size());
	for (int i : ans) printf("%d ", i);
	printf("\n");
	return 0;
}