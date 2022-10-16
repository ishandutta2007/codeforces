#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 500100;
int v[maxn], t[maxn];

bool next(int n){
	for (int i = 1; i <= n; ++i){
		int val = v[i - 1] + v[i] + v[i + 1];
		t[i] = val < 2 ? 0 : 1;
	}
	bool change = false;
	for (int i = 1; i <= n; ++i){
		if (v[i] != t[i])
			change = true;
		v[i] = t[i];
	}
	return change;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	
	v[0] = v[1];
	v[n + 1] = v[n];

	int ans = 0;

	for (int i = 1, j; i <= n; i = j){
		for (j = i + 1; v[j] != v[j - 1]; ++j);
		ans = max(ans, (j - i + 1) / 2 - 1);
		int p = (i + j + 1) / 2;
		for (int k = i + 1; k < j; ++k)
			v[k] = k < p ? v[i] : v[j];
	}

	cout << ans << endl;
	for (int i = 1; i <= n; ++i)
		cout << v[i] << " \n"[i == n];

	return 0;
}