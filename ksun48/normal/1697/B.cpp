#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<ll> p(n);
	for(ll& x : p){
		cin >> x;
	}
	sort(p.rbegin(), p.rend());
	vector<ll> psums(n+1);
	for(int i = 0; i < n; i++){
		psums[i+1] = psums[i] + p[i];
	}
	for(int i = 0; i < q; i++){
		int y, x;
		cin >> y >> x;
		cout << (psums[y] - psums[y-x]) << '\n';
	}
}