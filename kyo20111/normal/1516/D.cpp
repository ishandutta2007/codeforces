#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q, a[100100], b[100100], l[100100], sp[20][100100];

int go(int s, int m){
	while(m){
		int b = 31 - __builtin_clz(m);
		s = sp[b][s] + 1;
		m -= (1 << b);
	}
	return s-1;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<=100000;i++) l[i] = n+1;
	int mn = n;

	for(int i=n;i>=1;i--){
		int x = a[i];

		for(int j=2;j*j<=x;j++) if(x % j == 0){
			mn = min(mn, l[j]-1), l[j] = i;
			while(x % j == 0) x /= j;
		}
		if(x > 1) mn = min(mn, l[x]-1), l[x] = i;

		b[i] = mn;
		sp[0][i] = mn;
	}

	for(int i=0;i<20;i++) sp[i][n+1] = n;

	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			sp[i][j] = sp[i-1][sp[i-1][j]+1];
		}
	}

	while(q--){
		int s, e; cin >> s >> e;

		int l = 1, r = n;
		while(l <= r){
			int m = (l + r) / 2;

			int k = go(s, m);

			if(k >= e) r = m-1;
			else l = m+1;
		}

		cout << l << "\n";
	}
}