#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
map <int, int> M;
ll res;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		M.clear();
		res = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			res += M[a - i]++;
		}
		printf("%I64d\n", res);
	}
    return 0;
}