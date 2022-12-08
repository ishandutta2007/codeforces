#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t; scanf ("%d", &t); while (t--){
		int n, k; scanf ("%d %d", &n, &k);
		for (int i = 0; i < k; i++) putchar('c');
		for (int i = 0; i < n - k; i++) putchar(i % 3 + 'a');
		puts("");
	}
	return 0;
}