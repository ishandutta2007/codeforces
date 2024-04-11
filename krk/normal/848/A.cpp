#include <bits/stdc++.h>
using namespace std;

int k;

int main()
{
	scanf("%d", &k);
	if (k == 0) { printf("a\n"); return 0; }
	char cur = 'a';
	while (k > 0) {
		int my = 1;
		while (my * (my - 1) / 2 <= k) my++;
		my--;
		k -= my * (my - 1) / 2;
		while (my--)
			printf("%c", cur);
		cur++;
	}
	printf("\n");
	return 0;
}