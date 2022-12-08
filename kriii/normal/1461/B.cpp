#include <cstdio>
#include <algorithm>
using namespace std;

int n, m; char s[505][505]; int d[505][505];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d %d", &n, &m);
		long long a = 0;
		for (int i = 0; i < n; i++) scanf ("%s", s[i]);
		for (int i = n - 1; i >= 0; i--){
			for (int j = 0; j < m; j++){
				if (s[i][j] == '.') d[i][j] = 0;
				else{
					if (i + 1 < n && s[i + 1][j] != '.'){
						int p = j - 1 >= 0 ? d[i + 1][j - 1] : 0;
						int q = j + 1 < m ? d[i + 1][j + 1] : 0;
						d[i][j] = min(p, q) + 1;
					}
					else d[i][j] = 1;

					a += d[i][j];
				}
			}
		}
		printf ("%lld\n", a);
	}
	return 0;
}