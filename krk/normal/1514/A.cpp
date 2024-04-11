#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		bool good = false;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			int b = 1;
			while (b * b < a) b++;
			if (b * b != a) good = true;
		}
		printf("%s\n", good? "YES": "NO");
	}
    return 0;
}