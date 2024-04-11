#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
// typedef complex<int64> point;
typedef pair<int64,int64> point;

#define real() first
#define imag() second

point fix(point a){
	int64 g = __gcd(abs(a.real()), abs(a.imag()));
	return point(a.real() / g, a.imag() / g);
}

map<point,int> m;

int64 cross(const point &a, const point &b){
	return  a.real() * b.imag() - a.imag() * b.real();
}

int quad(const point &a){
	if (a.real() > 0 && a.imag() >= 0) return 1;
	if (a.real() <= 0 && a.imag() > 0) return 2;
	if (a.real() < 0 && a.imag() <= 0) return 3;
	return 4;
}

int64 compare(const point &a, const point &b){
	return quad(a) < quad(b) || (quad(a) == quad(b) && cross(a, b) > 0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, c, d;
	cin >> n >> c >> d;

	vector<point> lst;
	vector<int> pnt;
	vector<int> acc;

	for (int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		x -= c; y -= d;
		point p = fix(point(x, y));
		if (m.find(p) == m.end())
			lst.push_back(p);
		m[p]++;
	}

	sort(lst.begin(), lst.end(), compare);
	
	n = lst.size();
	for (int i = 0; i < n; ++i)
		lst.push_back(lst[i]);

	pnt.resize(lst.size());
	acc.resize(lst.size());

	// cout << n << endl;

	for (int i = 0; i < n; ++i){
		if (pnt[i] == i) ++pnt[i];
		while (cross(lst[i], lst[pnt[i]]) > 0)
			acc[i] += m[lst[pnt[i]++]];
		acc[i + n] = acc[i];
		pnt[i + 1] = pnt[i];
		if (i + 1 != n) acc[i + 1] = max(0, acc[i] - m[lst[i + 1]]);
		// cout << lst[i].first << " " << lst[i].second << " ptr:" 
		// << pnt[i] << " freq:" << m[lst[i]] << " acc:" << acc[i] << endl;
	}

	int64 ans = 0;
	vector<int64> r(lst.size());

	// cout << endl; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// for (auto a : acc)
	// 	cout << a << " ";
	// cout << endl;

	for (int64 i = 0, ptr = 1, mult = 0; i < n; ++i){
		// cout << r[i] << " ";
		while (ptr < pnt[i]){
			r[i] = r[i] + (acc[ptr] - mult) * m[lst[ptr]];
			mult += m[lst[ptr]];
			++ptr;
		}
		// cout << r[i] << " ";
		mult -= m[lst[i + 1]];
		r[i + 1] = r[i] - m[lst[i + 1]] * (acc[i + 1] + m[lst[i + 1]] - acc[i]);
		// cout << r[i] << " ";
		if (pnt[i] != i + n && cross(lst[i], lst[pnt[i]]) == 0)
			r[i] -= acc[i] * m[lst[pnt[i]]];

		r[i] *= m[lst[i]];

		// cout << r[i] << endl;
		ans += r[i];
	}

	cout << ans / 3 << endl;



	return 0;
}

/*
7 0 0
-1 0
0 -1
1 1
2 2
0 1
1 0
-1 -1
*/