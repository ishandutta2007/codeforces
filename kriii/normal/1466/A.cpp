#include <stdio.h>
#include <bitset>
using namespace std;

int main()
{
	int t; scanf ("%d", &t); while (t--){
		int n, x[55];
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		bitset<66> chk;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) chk[x[j] - x[i]] = 1;
		printf ("%d\n", chk.count());
	}
	return 0;
}