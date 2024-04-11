#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 1000005;

int T;
int n, k;
char A[Maxn];
char B[Maxn];
int st[Maxl];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		fill(st, st + Maxl, 0);
		scanf("%s", A);
		for (int i = 0; i < n; i++)
			st[A[i] - 'a']++;
		scanf("%s", B);
		for (int i = 0; i < n; i++)
			st[B[i] - 'a']--;
		bool fall = false;
		for (int i = 0; i + 1 < Maxl; i++) {
			if (st[i] < 0) { fall = true; break; }
			else if (st[i] % k) { fall = true; break; }
			else st[i + 1] += st[i];
		}
		printf("%s\n", fall? "No": "Yes");
	}
    return 0;
}