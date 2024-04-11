#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
private:
	int v;
public:
	static const int MOD = MOD_;

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}

	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}

	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9) + 7>;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> z(n);
	for(int i = 0; i < n; i++) cin >> z[i];
	// not including that cell
	vector<vector<int> > nright(n, vector<int>(m, 0));
	vector<vector<int> > ndown(n, vector<int>(m, 0));
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(i + 1 < n) ndown[i][j] += ndown[i+1][j];
			if(j + 1 < m) nright[i][j] += nright[i][j+1];
			if(z[i][j] == 'R'){
				ndown[i][j]++;
				nright[i][j]++;
			}
		}
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			ndown[i][j] = n-1 - ndown[i][j];
			nright[i][j] = m-1 - nright[i][j];
			if(z[i][j] == 'R'){
				ndown[i][j]++;
				nright[i][j]++;
			}
		}
	}

	vector<vector<pair<int,int> > > down_interval(n, vector<pair<int,int> >(m));
	vector<vector<pair<int,int> > > right_interval(n, vector<pair<int,int> >(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int a = j;
			if(j > 0) a = right_interval[i][j-1].first;
			int b = j;
			if(j > 0) b = right_interval[i][j-1].second;
			while(a + 1 < m && nright[i][a] < j) a++;
			right_interval[i][j] = {a, j};
		}
	}
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			int a = i;
			if(i > 0) a = down_interval[i-1][j].first;
			while(a + 1 < n && ndown[a][j] < i) a++;
			down_interval[i][j] = {a, i};
		}
	}

	assert(down_interval[0][0].first == 0 && down_interval[0][0].second == 0);


	vector<vector<num> > down_moves(n, vector<num>(m, 0));
	vector<vector<num> > right_moves(n, vector<num>(m, 0));
	down_moves[0][0] = right_moves[0][0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i > 0){
				if(i > 1 || j > 0) down_moves[i][j] += down_moves[i-1][j];
				for(int x = down_interval[i-1][j].second; x < down_interval[i][j].second; x++){
					down_moves[i][j] += right_moves[x][j];
				}
				for(int x = down_interval[i-1][j].first; x < down_interval[i][j].first; x++){
					down_moves[i][j] -= right_moves[x][j];
				}
			}
			if(j > 0){
				if(j > 1 || i > 0) right_moves[i][j] += right_moves[i][j-1];
				for(int x = right_interval[i][j-1].second; x < right_interval[i][j].second; x++){
					right_moves[i][j] += down_moves[i][x];
				}
				for(int x = right_interval[i][j-1].first; x < right_interval[i][j].first; x++){
					right_moves[i][j] -= down_moves[i][x];
				}
			}
		}
	}

	num ans = down_moves[n-1][m-1] + right_moves[n-1][m-1];

	if(z[n-1][m-1] == 'R') ans = 0;
	if(n == 1 && m == 1) ans = 1;
	cout << (int)ans << '\n';
}