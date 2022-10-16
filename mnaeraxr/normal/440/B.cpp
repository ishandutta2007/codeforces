#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
	int n; cin >> n;

	vector<int64> V(n);
	int64 s = 0;
	for (int i = 0; i < n; ++i){
		cin >> V[i];
		s += V[i];		
	}
	int64 d = s / n;
        int64 ans = 0;
	for (int i = 0; i < n; ++i){
		ans += abs(V[i] - d);
		if (i + 1 < n) V[i + 1] += V[i] - d;
	}
	cout << ans << endl;
}