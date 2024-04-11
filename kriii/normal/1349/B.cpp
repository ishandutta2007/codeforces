#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, a[100100];
void solve()
{
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
	
	if (n == 1){
		puts(a[0] == k ? "yes" : "no");
		return;
	}

	bool g = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == k){
			g = 1;
			if (i && a[i - 1] >= k){
				puts("yes");
				return;
			}
			if (i + 1 < n && k <= a[i + 1]){
				puts("yes");
				return;
			}
		}
	}

	if (!g){
		puts("no");
		return;
	}

	for (int i = 1; i < n; i++){
		if (a[i - 1] >= k && a[i] >= k){
			puts("yes");
			return;
		}
	}

	for (int i = 2; i < n; i++){
		if (a[i - 2] >= k && a[i] >= k){
			puts("yes");
			return;
		}
	}

	puts("no");
}

int main()
{
	int t; scanf ("%d", &t); while (t--) solve();
	return 0;
}