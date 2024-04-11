#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int A[1005];

signed main() {
	// your code goes here
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	int ans = 0;
	
	vector <int> V = {0};
	for (int i = 1; i<=n; i++) {
		if (i % 2 == 1) V.push_back(V.back() + A[i]);
		else V.push_back(V.back() - A[i]);
	}
	
	int x = 0;
	
	for (int j = 2; j<=n; j+=2) {
		int t = A[j] + min(0ll, V[j] - x);
		vector <int> local_min;
		for (int i = j-2; i >= 0; i-=2) {
			if (V[i] < V[j]) break;
			if (local_min.size() > 0) if (V[i] > local_min.back()) continue;
			local_min.push_back(V[i]);
		}
		t += local_min.size();
		if (local_min.size() > 0) if (local_min.back() == x) t--;
		x = min(x, V[j]);
		ans += t;
	}
	
	cout << ans;
}