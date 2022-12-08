#include <stdio.h>
#include <bitset>
using namespace std;

int n, cnt[200200];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d", &n);
		for (int i = 0; i <= 2 * n + 1; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++){
			int x; scanf ("%d", &x);
			cnt[x]++;
		}

		for (int k = 2 * n; k >= 0; k--){
			if (cnt[k] && !cnt[k + 1]){
				cnt[k]--;
				cnt[k + 1]++;
			}
		}
		int ans = 0;
		for (int k = 0; k <= 2 * n + 1; k++) if (cnt[k]) ans++;
		printf ("%d\n", ans);
	}

	return 0;
}