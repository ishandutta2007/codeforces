#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int T;
int n;
vector <int> A, B;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		A.clear(); B.clear();
		for (int i = 0; i < 2 * n; i++) {
			int x, y; scanf("%d %d", &x, &y);
			if (x == 0) A.push_back(abs(y));
			else B.push_back(abs(x));
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		ld res = 0;
		for (int i = 0; i < A.size(); i++)
			res += sqrt(ld(A[i]) * A[i] + ld(B[i]) * B[i]);
		cout << fixed << setprecision(10) << res << endl;
	}
    return 0;
}