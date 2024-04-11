#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int n, k;
string s;

int main()
{
	cin >> n >> k;
	cin >> s;
	if (k - 1 <= n - k) {
		for (int i = 0; i < k - 1; i++)
			printf("LEFT\n");
		for (int i = 0; i < n; i++) {
			printf("PRINT %c\n", s[i]);
			if (i + 1 < n) printf("RIGHT\n");
		}
	} else {
		for (int i = 0; i < n - k; i++)
			printf("RIGHT\n");
		for (int i = n - 1; i >= 0; i--) {
			printf("PRINT %c\n", s[i]);
			if (i - 1 >= 0) printf("LEFT\n");
		}
	}
	return 0;
}