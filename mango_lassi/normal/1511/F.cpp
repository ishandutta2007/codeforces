#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

template<ll P>
struct ModNum {
	ll v;
	ModNum(ll val) : v(val) {}
	operator ll() const { return v; }

	ModNum operator+(const ModNum& rhs) { ll res = v + rhs.v; return res >= MOD ? res - MOD : res; }
	ModNum operator-(const ModNum& rhs) { ll res = v - rhs.v; return res >= 0 ? res : res + MOD; }
	ModNum operator*(const ModNum& rhs) { return v * rhs.v % MOD; }
	ModNum operator/(const ModNum& rhs) { return v * rhs.pow(MOD - 2) % MOD; }
	ModNum& operator+=(const ModNum& rhs) { v += rhs.v; if (v >= MOD) v -= MOD; return *this; }
	ModNum& operator-=(const ModNum& rhs) { v -= rhs.v; if (v < 0) v += MOD; return *this; }
	ModNum& operator*=(const ModNum& rhs) { v = v * rhs.v % MOD; return *this; }
	ModNum& operator/=(const ModNum& rhs) { v = v * rhs.pow(MOD - 2) % MOD; return *this; }
	
	ModNum pow(ll b) const {
		ModNum res(1), cur(v);
		for (ll j = 1; j <= b; j <<= 1) {
			if (b & j) res *= cur;
			cur *= cur;
		}
		return res;
	}
};
using num = ModNum<MOD>;

constexpr int bLog(ll v) { return v ? 63 - __builtin_clzll(v) : 0; }
template<class T>
T itPow(const T& a, ll d, T r = 1) {
        for (ll b = 1ll << bLog(d); b > 0; b /= 2) {
                r = r*r;
                if (d & b) r = r*a;
        }
        return r;
}

// Assumes 0 and 1 are 0,1 for T
template<class T>
struct Matrix {
	vector<T> mat;
	int h, w;

	Matrix(int height, int width) : h(height), w(width), mat(height*width, 0) {}

	const T& operator()(int y, int x) const {
		return mat[x+y*w];
	}
	T& operator()(int y, int x) {
		return mat[x+y*w];
	}
	static Matrix ident(int n) {
		Matrix res(n, n);
		for (int i = 0; i < n; ++i) res(i, i) = 1;
		return res;
	}
	Matrix& operator+=(const Matrix& rhs) {
		assert(h == rhs.h && w == rhs.w);
		for (int i = 0; i < w*h; ++i) mat[i] += rhs.mat[i];
	}
	Matrix operator*(const Matrix& rhs) const {
		assert(w == rhs.h);
		Matrix res(h, rhs.w);
		for (int i = 0; i < w; ++i) {
			int b1 = i * rhs.w;
			for (int y = 0; y < res.h; ++y) {
				T mult = mat[i + y * w];
				int b2 = y * res.w;
				for (int x = 0; x < res.w; ++x) {
					res.mat[b2 + x] += mult * rhs.mat[b1 + x];
				}
			}
		}
		return res;
	}
};
using Mat = Matrix<num>;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

string getSuff(const string& str, int k) {
	string res(k, '_');
	for (int i = 0; i < k; ++i) res[i] = str[(int)str.size() - k + i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Over every string of length m, add (#ways to make it by appending words from dictionary)^2

	// Current state:
	//	Current number of characters
	//	suffix of some word that is currently unfilled
	// 	

	int n, m;
	cin >> n >> m;

	vector<string> words(n);
	for (int i = 0; i < n; ++i) cin >> words[i];
	
	vector<string> states;
	for (int i = 0; i < n; ++i) {
		for (int k = 1; k <= words[i].size(); ++k) {
			states.emplace_back(getSuff(words[i], k));
		}
	}
	states.emplace_back("");

	sort(states.begin(), states.end());
	states.erase(unique(states.begin(), states.end()), states.end());

	int ss = states.size();
	
	/*
	cerr << ss << ": ";
	for (auto str : states) cerr << "[" << str << "] "; cerr << '\n';
	*/

	vector<pair<int, int>> ord(ss);
	for (int i = 0; i < ss; ++i) ord[i] = {(int)states[i].size(), i};
	sort(ord.begin(), ord.end());

	vector<num> zw(ss, 0);
	zw[0] = 1;

	vector<vector<pair<int, int>>> ts(ss);
	for (auto pr : ord) {
		int i = pr.second;
		string stat = states[i];
		for (int j = 0; j < words.size(); ++j) {
			string wrd = words[j];
			if (wrd.empty()) continue;

			bool works = 1;
			for (int t = 0; t < min(stat.size(), wrd.size()); ++t) {
				if (stat[t] != wrd[t]) works = 0;
			}
			if (works) {
				if (stat.size() >= wrd.size()) {
					string rem = getSuff(stat, (int)stat.size() - (int)wrd.size());
					int t = bins(states, rem);
					zw[i] += zw[t];
					for (auto pr2 : ts[t]) {
						ts[i].emplace_back(pr2.first, pr2.second);
					}
				} else {
					string rem = getSuff(wrd, (int)wrd.size() - (int)stat.size());
					int t = bins(states, rem);
					ts[i].emplace_back(t, (int)rem.size());
				}
			}
		}
		// cerr << i << ' ' << zw[i] << '\n';
	}

	/*
	for (int s = 0; s < ss; ++s) {
		cerr << states[s] << " " << zw[s] << ": ";
		for (auto pr : ts[s]) cerr << states[pr.first] << ' ' << pr.second << ", ";
		cerr << '\n';
	}
	*/

	Mat mat(5 * ss, 5 * ss);
	for (int y = 0; y < ss; ++y) {
		for (int j = 0; j < 4; ++j) {
			int b = y + j * ss;
			mat(b + ss, b) = 1;
		}
	}
	for (int s = 0; s < ss; ++s) {
		for (auto pr : ts[s]) {
			mat((5 - pr.second)*ss + s, 4*ss + pr.first) += 1;
		}
	}
	
	/*
	for (int y = 0; y < 5*ss; ++y) {
		for (int x = 0; x < 5*ss; ++x) {
			cerr << mat(y, x) << ' ';
		}
		cerr << '\n';
	}
	*/

	Mat res = itPow(mat, m, mat.ident(5 * ss));

	/*
	for (int y = 0; y < 5*ss; ++y) {
		for (int x = 0; x < 5*ss; ++x) {
			cerr << res(y, x) << ' ';
		}
		cerr << '\n';
	}
	*/

	num ans = 0;
	for (int s = 0; s < ss; ++s) ans += res(4*ss, 4*ss + s) * zw[s];
	cout << ans << '\n';
}