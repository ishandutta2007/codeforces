#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<int64> point;

int quad(point a){
	if (a.real() > 0 && a.imag() >= 0) return 0;
	if (a.imag() > 0 && a.real() <= 0) return 1;
	if (a.real() < 0 && a.imag() <= 0) return 2;
	return 3;
}

int64 cross(point a, point b){
	return imag(conj(a) * b);
}

int64 dot(point a, point b){
	return a.real() * b.real() + a.imag() * b.imag();
}

int64 sign(int64 v){
	if (v < 0) return -1;
	if (v == 0) return 0;
	return 1;
}

bool compare(pair<point,int> aa, pair<point,int> bb){
	point a = aa.first, b = bb.first;
	if (quad(a) != quad(b)) return quad(a) < quad(b);
	return cross(a, b) > 0;
}

struct fraction
{
	int64 num, den;
	fraction (int64 N = 0, int64 D = 1){
		num = N, den = D;
		fix();
	}

	void fix(){
		int64 g = __gcd(abs(num), den);
		num /= g; den /= g;
	}

	void print() const{
		cout << num << "/" << den << endl;
	}

	fraction positive() const{
		return fraction(abs(num), den);
	}

	bool operator <(const fraction &b) const{
		// print(); b.print(); cout << endl;

		if (sign(num) != sign(b.num)) return sign(num) < sign(b.num);
		if (sign(num) == -1) return b.positive() < positive();

		// cout << "HERE" << endl;
		// cout << "HERE" << endl; print(); b.print();
		
		if (num == b.num && den == b.den) return false;
		// if (num == 0) return b.num != 0;
		// if (b.num == 0) return false;

		if (num / den != b.num / b.den) return num / den < b.num / b.den;
		
		if (den == 1) return b.den > 1;
		if (b.den == 1) return false;

		// cout << "HERE" << endl;
		return fraction(b.den, b.num % b.den) < fraction(den, num % den);
	}
};

int64 sqr(int64 v){
	return v * v;
}

int64 __norm(point a){
	return sqr(a.real()) + sqr(a.imag());
}

fraction angle(point a, point b){
	int64 val = dot(a, b);
	return fraction(sign(val) * sqr(val),__norm(a) *__norm(b));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// cout << (fraction(16, 41) < fraction(529, 533)) << endl;
	// exit(0);

	int n; cin >> n;
	vector<pair<point,int>> v(n);
	for (int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		v[i] = make_pair(point(x, y), i + 1);
	}

	sort(v.begin(), v.end(), compare);
	v.push_back(v[0]);

	pii ans(v[0].second, v[1].second);
	fraction ang = angle(v[0].first, v[1].first);

	for (int i = 0; i < n; ++i){
		fraction curang = angle(v[i].first, v[i + 1].first);
		// cout << v[i].second << " " << v[i + 1].second << " ";curang.print();
		if (ang < curang){
			ang = curang;
			ans = make_pair(v[i].second, v[i + 1].second);
		}
	}

	// ang.print();
	cout << ans.first << " " << ans.second << endl;

	return 0;
}