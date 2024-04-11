#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 14;

int sg(int64 a){
	return a < 0 ? -1 : (a == 0 ? 0 : 1);
}

struct fraction{
	int64 num, den;
	fraction(int NUM = 0, int DEN = 1){
		num = NUM, den = DEN;
		fix();
	}

	void fix(){
		int64 g = __gcd(abs(num), den);
		num /= g;
		den /= g;
	}

	fraction operator +(const fraction &a) const{
		return fraction(num * a.den + den * a.num, den * a.den);
	}

	fraction operator *(const fraction &a) const{
		return fraction(num * a.num, den * a.den);
	}

	fraction operator -(const fraction &a){
		return *this + fraction(-1) * a;
	}

	bool operator <(const fraction &a){
		fraction cur = *this - a;
		return cur.num < 0;
	}

	void print(){
		assert(den == 1);
		cout << num << endl;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fraction points(0);
	vector<int> v(5);
	vector<int> w(5);
	for (int i = 0; i < 5; ++i) cin >> v[i];
	for (int i = 0; i < 5; ++i) cin >> w[i];

	for (int i = 0; i < 5; ++i){
		fraction p = fraction((i + 1) * 500) * (fraction(1) - fraction(v[i], 250)) - fraction(50 * w[i]);
		fraction t = fraction(3 * 500 * (i + 1), 10);
		if (p < t) points = points + t;
		else points = points + p;
	}

	int a, b; cin >> a >> b;
	points = points + fraction(100 * a) - fraction(50 * b);

	points.print();

	return 0;
}