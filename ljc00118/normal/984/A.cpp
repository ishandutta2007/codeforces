#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;

int a[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d", a[(n + 1) / 2]);
	return 0;
}