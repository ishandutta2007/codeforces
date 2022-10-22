#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long ll;
typedef long long llint;
typedef pair<llint, llint> P;

#define PI 3.141592653589793238

int rev(int x, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret <<= 1;
		ret |= (x>>i) & 1;
	}
	return ret;
}

void DFT(complex<double> f[], complex<double> F[], int n)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];

	complex<double> a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = complex<double>(cos(2*PI/l), sin(2*PI/l));
		for(int j = 0; j < N/l; j++){
			x = complex<double>(1, 0);
			for(int k = 0; k < l/2; k++){
				a = F[j*l+k], b = F[j*l+k+l/2];
				F[j*l+k] = a + x * b;
				F[j*l+k+l/2] = a - x * b;
				x *= z;
			}
		}
	}
}

void IDFT(complex<double> F[], complex<double> f[], int n)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];

	complex<double> a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = complex<double>(cos(2*PI/l), -sin(2*PI/l));
		for(int j = 0; j < N/l; j++){
			x = complex<double>(1, 0);
			for(int k = 0; k < l/2; k++){
				a = f[j*l+k], b = f[j*l+k+l/2];
				f[j*l+k] = a + x * b;
				f[j*l+k+l/2] = a - x * b;
				x *= z;
			}
		}
	}
	for(int i = 0; i < N; i++) f[i] /= N;
}

llint round(complex<double> c){
	return (llint)(c.real()+0.5);
}

ll T;
ll n;
string s;
bool used[500005];
complex<double> f[1<<20], g[1<<20], F[1<<20], G[1<<20];
vector<int> vec[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 1; i <= 500000; i++){
		for(int j = i; j <= 500000; j+=i) vec[j].push_back(i);
	}

	cin >> T;
	while(T--){
		cin >> n >> s;

		ll b = 0;
		for(ll t = 2*n+5; t; t/=2) b++;
		rep(i, 0, (1<<b)-1) f[i] = g[i] = 0;

		rep(i, 0, n-1){
			if(s[i] == 'K') f[i] = 1;
			if(s[i] == 'V') g[n-i] = 1;
		}

		DFT(f, F, b), DFT(g, G, b);
		rep(i, 0, (1<<b)-1) F[i] *= G[i];
		IDFT(F, f, b);

		rep(i, 1, n) used[i] = false;
		rep(i, 0, (1<<b)-1){
			if(round(f[i]) == 0) continue;
			ll d = abs(i-n);
			for(auto x : vec[d]) used[x] = true;
		}

		vector<ll> ans;
		rep(i, 1, n) if(!used[i]) ans.push_back(i);
		cout << ans.size() << "\n";
		for(auto x : ans) cout << x << " "; cout << "\n";
	}
	flush(cout);

	return 0;
}