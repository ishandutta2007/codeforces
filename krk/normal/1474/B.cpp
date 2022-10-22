#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		int d; scanf("%d", &d);
		int a = 1 + d;
		while (!Prime(a)) a++;
		int b = a + d;
		while (!Prime(b)) b++;
		cout << ll(a) * b << "\n";
	}
    return 0;
}