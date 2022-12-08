#include <stdio.h>
#include <algorithm>
using namespace std;

int n; char S[200200];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d", &n);
		scanf ("%s", S);

		int g = 1;
		for (int i = 1; i < n; i++) if (S[i] != S[0]) g = 0;
		if (g) printf ("%d\n", (n + 2) / 3);
		else{
			int a = 0;

			S[n] = S[0];
			for (int i = 0; i < n; i++) if (S[i] == 'R' && S[i + 1] == 'L'){
				int p = i, x = 0;
				while (S[p] == 'R'){
					x++; p = (p + n - 1) % n;
				}
				int q = i + 1, y = 0;
				while (S[q] == 'L'){
					y++; q = (q + 1) % n;
				}
				a += x / 3;
				a += y / 3;
			}
			printf ("%d\n", a);
		}
	}

	return 0;
}