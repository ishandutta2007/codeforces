#include <bits/stdc++.h>
using namespace std;

string abc = "abc";
int t;

int main()
{
	scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			printf("%c", abc[i % 3]);
		printf("\n");
	}
    return 0;
}