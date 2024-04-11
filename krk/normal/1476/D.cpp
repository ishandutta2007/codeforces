#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n;
char str[Maxn];
int L1[Maxn], L2[Maxn];
int R1[Maxn], R2[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		for (int i = 0; i <= n; i++) {
			L1[i] = str[i] == 'L'? 1 + (i > 0? L2[i - 1]: 0): 0;
			L2[i] = str[i] == 'R'? 1 + (i > 0? L1[i - 1]: 0): 0;
		}
		for (int i = n; i >= 0; i--) {
			R1[i] = str[i] == 'L'? 1 + (i < n? R2[i + 1]: 0): 0;
			R2[i] = str[i] == 'R'? 1 + (i < n? R1[i + 1]: 0): 0;
		}
		for (int i = 0; i <= n; i++) {
			int ans = 1;
			if (i > 0) ans += L1[i - 1];
			ans += R2[i];
			printf("%d%c", ans, i + 1 <= n? ' ': '\n'); 
		}
	}
    return 0;
}