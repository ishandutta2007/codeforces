#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

struct primes_ {
	std::vector<int> d;
	primes_(int n): d(n+2) {
		std::vector<bool> s(n+1);
		d[0] = 2; d[1] = 3;
		int sz = 2;
		bool f = false;
		for(int p = 5; p <= n; p += (f = !f) ? 2 : 4) {
			if (!s[p]) {
				d[sz++] = p;
				if ((long long)p * p <= n) {
					for(int x=p*p; x<=n; x+=p) s[x] = true;
				}
			}
		}
		d.resize(sz);
	}
	auto begin() {return d.begin();}
	auto end() {return d.end();}
} primes(100000);

bool is_prime(int x) {
    for(int p = 2; p * p <= x; ++p) {
        if (x % p == 0) return false;
    }
    return true;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VVI ans(n, VI(n, 4));
        rep(i, n) ans[i][i] = 1;
        int tot = 1 + (n - 1) * 4;
        rep(j, n-1) ans[0][j+1] = 421-(tot-4);
        rep(i, n-1) ans[i+1][0] = 421-(tot-4);
        int s = (421-(tot-4)) * (n-1);
        int p;
        for(int x = int(primes.d.size()) - 1; x >= 0; x--) {
            //cout << x << endl;
            p = primes.d[x];
            if (!is_prime(p - s)) break;
        }
        //cout << p << endl;
        ans[0][0] = p - s;
        rep(i, n) rep(j, n) cout << ans[i][j] << " \n"[j + 1 == n];
    }
}