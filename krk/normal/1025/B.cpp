#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
set <int> S;

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0) {
			S.insert(i);
			while (a % i == 0)
				a /= i;
		}
	if (a > 1) S.insert(a);
	for (int i = 2; i * i <= b; i++)
		if (b % i == 0) {
			S.insert(i);
			while (b % i == 0)
				b /= i;
		}
	if (b > 1) S.insert(b);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (set <int>::iterator it = S.begin(); it != S.end(); )
			if (a % *it != 0 && b % *it != 0) S.erase(it++);
			else it++;
	}
	if (S.empty()) printf("-1\n");
	else printf("%d\n", *S.begin());
	return 0;
}