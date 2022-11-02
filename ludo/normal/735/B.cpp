#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, n1, n2;
    cin >> n >> n1 >> n2;
    for (int i = 0; i < n; i++) {
		cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);

    if (n1 > n2) swap(n1, n2);

	// n1 <= n2
	// max{ sum(S_1)*n2 + sum(S_2)*n1 }

	double ret = 0.0, avg1 = 0.0, avg2 = 0.0;
	for (int i = 0; i < n1; i++) avg1 += a[i];
	for (int i = n1; i < n1 + n2; i++) avg2 += a[i];
	ret = avg1 / n1 + avg2 / n2;
	cout.precision(10);
	cout << fixed;
	cout << ret << endl;
//	for (int i = 0; i < n; i++) {
//		cerr << a[i] << " ";
//	}
    return 0;
}