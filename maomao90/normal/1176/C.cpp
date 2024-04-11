#include <bits/stdc++.h>
using namespace std;

int arr[] = {4, 8, 15, 16, 23, 42};

int n;
int a[500005];
multiset<int> pointer;
int ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[j] == a[i]) {
				if (j == 0) pointer.insert(j);
				else if (pointer.find(j - 1) != pointer.end()) {
					pointer.erase(pointer.find(j - 1));
					if (j != 5) pointer.insert(j);
				} else ans++;
				break;
			}
		}
	}
	for (auto &i : pointer) ans += i + 1;
	printf("%d\n", ans);
	return 0;
}