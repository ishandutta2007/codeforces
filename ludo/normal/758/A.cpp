#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N, x, s = 0, m = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		s += x;
		m = max(m, x);
	}
	cout << (m * N - s) << endl;
	return 0;
}