#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int b[N];
vector<int> A, B;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (i > 1) {
			A.push_back(a[i] - a[i - 1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
		if (i > 1) {
			B.push_back(b[i] - b[i - 1]);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if (a[1] == b[1] && a[n] == b[n] && A == B) {
		puts("Yes");
	} else {
		puts("No");
	}
}