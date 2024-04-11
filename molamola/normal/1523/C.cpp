#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

void solve() {
	int n;
	scanf("%d", &n);
	vector <int> v;
	auto output = [&](vector <int> &x) {
		int n = szz(x);
		printf("%d", x[0]);
		for(int i=1;i<n;i++) printf(".%d", x[i]);
		puts("");
	};
	rep(i, n) {
		int x; scanf("%d", &x);
		if(x == 1) v.pb(1);
		else {
			while(v.back() != x - 1) v.pop_back();
			v.pop_back();
			v.pb(x);
		}
		output(v);
	}
}

int main() {
	int T; scanf("%d", &T);
	rep(tt, T) {
		solve();
	}
	return 0;
}