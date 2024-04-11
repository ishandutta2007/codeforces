#include <stdio.h>
#include <vector>
using namespace std;

int n, a[1010]; bool chk[1010];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);

		vector<int> ans;
		while (1){
			for (int j = 0; j <= n; j++) chk[j] = 0;
			for (int i = 0; i < n; i++) chk[a[i]] = 1;

			bool ed = 0;
			for (int j = 0; j <= n; j++) if (!chk[j]){
				if (j == n){ ed = 1; break; }
				ans.push_back(j + 1);
				a[j] = j;
				break;
			}
			//for (int i = 0; i < n; i++) printf ("%d ", a[i]); puts("");
			if (ed){
				bool red = 1;
				for (int j = 0; j < n; j++) if (a[j] != j){
					ans.push_back(j + 1);
					a[j] = n;
					red = 0;
					break;
				}
				if (red) break;
			}
		}

		printf ("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) printf ("%d ", ans[i]); puts("");
	}
	return 0;
}