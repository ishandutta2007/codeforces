#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int num = min(a, min(b - 1, c - 2));
	printf("%d\n", 3 * num + 3);
}