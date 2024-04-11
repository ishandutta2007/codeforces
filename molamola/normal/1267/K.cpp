#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define pli pair<long long,int>

int T;

ll solve(vector <int> w) {
	int m = (int)w.size();
	ll ans = 1;
	for(int i=1;i<=m;i++) {
		int c = 0;
		for(int e : w) if(e <= i) ++c;
		if(c - (i - 1) <= 0) return 0;
		ans = ans * (c - (i - 1));
	}
	sort(w.begin(), w.end());
	for(int i=0, j=0;i<m;i++) {
		if(i == m-1 || w[i] != w[i+1]) {
			for(int k=1;k<=i-j+1;k++) ans /= k;
			j = i + 1;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		ll V; scanf("%lld", &V);
		vector <int> w;
		for(int k=2;V;k++) {
			w.pb(V % k);
			V /= k;
		}
		sort(w.begin(), w.end());
		ll ans = solve(w);
		if(w[0] == 0) {
			w.erase(w.begin());
			ans -= solve(w);
		}
		printf("%lld\n", ans - 1);
	}
}