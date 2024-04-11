#include <cstdio>
#include <vector>
using namespace std;

int n, k;
int a[105];
vector <int> arr;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) arr.push_back(i);
	int cur = 0;
	for (int i = 0; i < k; i++) {
		int nxt = (cur + a[i]) % (int) arr.size();
		printf("%d ", arr[nxt]);
		arr.erase(arr.begin() + nxt);
		cur = nxt;
	}
	printf("\n");
	return 0;
}