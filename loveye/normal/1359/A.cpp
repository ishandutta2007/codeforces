#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		int n,m,k;
		cin >> n >> m >> k;
		if(m <= n/k) cout << m << endl;
		else cout << (int)(n/k - ceil((m-n/k) / (double)(k-1))) << endl;
	}
	return 0;
}