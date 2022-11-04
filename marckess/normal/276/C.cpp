#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define MN 200000

int n, q, x, y;
vi a, cq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	a.assign(n, 0); cq.assign(n+2, 0);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < q; i++){
		cin >> x >> y;
		cq[x]++;
		cq[y+1]--;
	}
	
	for (int i = 1; i <= n; i++){
		cq[i] += cq[i-1];
	}
	
	sort(a.begin(), a.end(), greater<ll>());
	sort(cq.begin(), cq.end(), greater<ll>());
	
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] * cq[i];
	}
	
	cout << res << endl;
	
	return 0;
	
}