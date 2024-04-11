#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000000;

int T;
int n;
int win[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int d = 0;
		while (n % 2 == 0) {
			n /= 2;
			d++;
		}
		if (n == 1 && d % 2) printf("Bob\n");
		else if (d > 0) printf("Alice\n");
		else printf("Bob\n");
	}
    return 0;
}