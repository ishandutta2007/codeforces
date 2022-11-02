#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int cnt[N];
int tot;

void solve(vector<int> p, int k) {
    if (k == 0) {
	int inv = 0;
	for (int i = 0; i < p.size(); i++) 
	    for (int j = 0; j < i; j++)
		if (p[j] > p[i])
		    inv++;
	cnt[inv]++;
	tot++;
	return;
    }
    for (int i = 0; i < p.size(); i++)
	for (int j = 0; j <= i; j++) {
	    reverse(p.begin() + j, p.begin() + i + 1);
	    solve(p, k - 1);
	    reverse(p.begin() + j, p.begin() + i + 1);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
	cin >> p[i];
    double res = 0.0;
    solve(p, k);
    for (int i = 0; i <= n * (n - 1) / 2; i++)
	res += i * 1.0 * cnt[i] * 1.0 / tot;
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res << endl;
    return 0;
}