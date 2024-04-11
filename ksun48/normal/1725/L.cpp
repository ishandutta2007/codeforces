#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll X = 1e15;

struct FT {
	map<ll, ll> s;
	void update(ll pos, ll dif) { // a[pos] += dif
		for (; pos < X; pos |= pos + 1) s[pos] += dif;
	}
	ll query(ll pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll N;
	cin >> N;
	vector<ll> A(N);
	for(ll& x : A) cin >> x;
	vector<ll> psum(N+1, 0);
	for(int i = 0; i < N; i++){
		psum[i+1] = psum[i] + A[i];
	}
	for(int i = 0; i <= N; i++){
		if(psum[i] < psum[0] || psum[i] > psum[N]){
			cout << -1 << '\n';
			exit(0);
		}
	}
	ll ans = 0;
	FT ft;
	for(ll x : psum){
		ans += ft.query(X-1) - ft.query(x+1);
		ft.update(x, 1);
	}
	cout << ans << '\n';
}