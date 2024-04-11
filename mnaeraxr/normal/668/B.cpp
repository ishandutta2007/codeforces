#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	int n, q; 
	scanf("%d%d", &n, &q);

	int odd = 0;
	int even = 0;

	for (int i = 0; i < q; ++i){
	    int t; scanf("%d", &t);
		if (t == 1){
			int v; scanf("%d", &v);
			odd = (odd + v + 2 * n) % n;
			even = (even + v + 2 * n) % n;
		}
		else{
			if (odd & 1){
				odd = (odd - 1 + n) % n;
				even = (even + 1) % n;
			}
			else{
				odd = (odd + 1) % n;
				even = (even - 1 + n) % n;
			}
		}
	}

	vector<int> ans(n);

	for (int i = 0; i < n; ++i){
		if (i & 1){
			// Even (Base indexed change parity)
			ans[(i + even) % n] = i + 1;
		}
		else{
			ans[(i + odd) % n] = i + 1;
		}
	}

	for (int i = 0; i < n; ++i)
	    printf("%d ", ans[i]);
	putchar('\n');


	return 0;
}