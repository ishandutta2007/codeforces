#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef complex<ld> comp;
typedef vector<comp> vc;
const ld PI = acos(-1.0);

int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}

void fft(vector<comp> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	vector<comp> wp(n>>1);
	for(int k = 1; k < n; k <<= 1){
		for(int j = 0; j < k; ++j)
			wp[j] = polar(ld(1), PI * j / k * inv);
		for(int i = 0; i < n; i += k << 1){
			for(int j = 0; j < k; ++j){
				comp t = X[i + j + k] * wp[j];
				X[i + j + k] = X[i + j] - t;
				X[i + j] += t;
			}
		}
	}
	if(inv == -1)
		for(int i = 0; i < n; ++i)
			X[i] /= n;
}

vector<comp> convolution(vector<comp> A, vector<comp> B){
	int sz = A.size() + B.size() - 1;
	int size = nearestPowerOfTwo(sz);
	A.resize(size), B.resize(size);
	fft(A, 1), fft(B, 1);
	for(int i = 0; i < size; i++)
		A[i] *= B[i];
	fft(A, -1);
	A.resize(sz);
	return A;
}

const int MX = 1000005;
int n, x, y, a[MX], mx[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> y;
	n++;

	vc p(x + 1), q(x + 1);
	forn (i, n) {
		cin >> a[i];

		p[a[i]] = 1;
		q[x - a[i]] = 1;
	}

	p = convolution(p, q);

	forn (i, p.size()) if (i - x > 0 && ll(p[i].real() + 0.5)) {
		int k = i - x + y;

		for (int t = k; t < MX; t += k)
			if (k > mx[t])
				mx[t] = k;
	}

	{
		int q;
		cin >> q;
		while (q--) {
			int l;
			cin >> l;
			l /= 2;

			if (mx[l]) cout << 2 * mx[l] << " ";
			else cout << -1 << " ";
		}

		cout << endl;
	}

	return 0;
}