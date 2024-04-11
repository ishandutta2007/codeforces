#include <bits/stdc++.h>
using namespace std;

const string num = "989";

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n && i < num.length(); i++)
			printf("%c", num[i]);
		for (int i = num.length(); i < n; i++)
			printf("%d", (i - num.length()) % 10);
		printf("\n");
	}
    return 0;
}