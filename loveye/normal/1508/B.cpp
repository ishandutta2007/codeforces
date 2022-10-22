#include<bits/stdc++.h>
using namespace std;
int nn,t;
long long k;
void solve(int n,long long k,int s = 0) {
	if(n >= 63) return cout << s+1 << ' ',solve(n-1,k,s+1);
	if(n && (k >> n-1 & 1)) return solve(n-1,k ^ (1ll << n-1),s);
	for(int i = nn-n;i > s;--i)  cout << i << ' ';
	if(n) solve(n-1,k,nn-n);
}
int main() {
	cin >> t;
	while(t--) {
		cin >> nn >> k;
		if(nn < 63 && (1ll << nn-1) < k) cout << -1 << endl;
		else solve(nn,k-1),cout << endl;
	}
	return 0;
}