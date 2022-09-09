#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//freopen("c3.out", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {


}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//#define int li

template <typename T>
class myComplex {
private:
	T x, y;
public:
	myComplex() {}
	myComplex(T x, T y) :x(x), y(y) {}
	myComplex(T x) :x(x), y(0) {}
	T getReal() {
		return x;
	}
	T getImag() {
		return y;
	}
	T getSqrDist() {
		return x * x + y * y;
	}
	double getDist() {
		return sqrt(1.0 * getSqrDist());
	}
	myComplex operator + (const myComplex& other) const { return myComplex(x + other.x, y + other.y); }
	myComplex operator - () { return myComplex(-x, -y); }
	myComplex operator - (const myComplex& other) const { return myComplex(x - other.x, y - other.y); }
	myComplex operator * (T number) { return myComplex(x * number, y * number); }
	myComplex operator / (T number) { return myComplex(x / number, y / number); }
	myComplex operator * (const myComplex& other) const { return myComplex(x * other.x - y * other.y, x * other.y + y * other.x); }
	void print() const {
		cout << x;
		if (y > 0)
			cout << "+";
		if (y != 0)
			cout << y << "i";
		cout << "\n";
	}

};

//#define double long double

typedef myComplex<double> complex;

double PI = acos((double)-1.0);

void fft(vector<complex> & a, bool invert) {
	int n = (int)a.size();

	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		complex wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			complex w(1);
			for (int j = 0; j < len / 2; ++j) {
				complex u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w = w * wlen;
			}
		}
	}
	if (invert)
		for (int i = 0; i<n; ++i)
			a[i] = a[i] / n;
}

vector <int> multiply(const vector<int>& a, const vector<int>& b, bool f = true) {
	int n = 1;
	while (n <= a.size() || n <= b.size())
		n <<= 1;
	n <<= 1;
	vector<complex> input[2];
	for (int w = 0; w < 2; ++w)
		input[w].assign(n, complex(0, 0));
	for (int i = 0; i < a.size(); ++i)
		input[0][i] = a[i];
	for (int i = 0; i < b.size(); ++i)
		input[1][i] = b[i];
	for (int w = 0; w < 2; ++w) {
		fft(input[w], false);
	}
	vector <complex> res(n);
	for (int i = 0; i < n; ++i)
		res[i] = input[0][i] * input[1][i];
	fft(res, true);
	vector<int> answer;
	for (int i = 0; i < n; ++i)
		answer.push_back(int(res[i].getReal() + 0.1));
	return answer;
}


void solve() {
	string alphabet = "ACGT";
	map<char, int> getId;
	for (int i = 0; i < 4; ++i) {
		getId[alphabet[i]] = i;
	}
	int k;
	string s, t;
	int n, m;
	cin >> n >> m >> k;
	cin >> s >> t;
	vector<int> a(s.length());
	for (int i = 0; i < a.size(); ++i) {
		a[i] = getId[s[i]];
	}
	vector<int> b(t.length());
	for (int i = 0; i < b.size(); ++i) {
		b[i] = getId[t[i]];
	}

	vector<vector<char>> good(4, vector<char>(a.size(), false));

	vector<int> last(4, -1e9);
	for (int i = 0; i < a.size(); ++i) {
		last[a[i]] = i;
		for (int j = 0; j < 4; ++j) {
			if (i <= last[j] + k) {
				good[j][i] = true;
			}
		}
	}
	last.assign(4, 1e9);
	for (int i = a.size() - 1; i >= 0; --i) {
		last[a[i]] = i;
		for (int j = 0; j < 4; ++j) {
			if (i + k >= last[j]) {
				good[j][i] = true;
			}
		}
	}

	vector<char> correct(a.size(), true);

	for (int j = 0; j < 4; ++j) {
		vector<int> badPoses(a.size(), 0);
		for (int i = 0; i < a.size(); ++i) {
			if (!good[j][i]) {
				badPoses[i] = 1;
			}
		}

		vector<int> needIndices(b.size(), 0);
		for (int i = 0; i < b.size(); ++i) {
			if (b[i] == j) {
				needIndices[i] = 1;
			}
		}

		reverse(all(needIndices));

		vector<int> curRes = multiply(badPoses, needIndices);
		
		for (int curPos = b.size() - 1; curPos < curRes.size(); ++curPos) {
			if (!curRes[curPos])
				continue;
			int badId = curPos - (int)b.size() + 1;
			if (badId < a.size()) {
				correct[badId] = false;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i + b.size() <= a.size(); ++i) {
		if (correct[i]) {
			++ans;
		}
	}

	cout << ans << "\n";

}