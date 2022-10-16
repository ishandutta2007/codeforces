#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'
#define double long double

typedef	long long int64;
typedef complex<int64> point;

int64 cross(point a, point b){
	return imag(conj(a) * b);
}

bool compare(const point &a, const point &b){
	return cross(a, b) > 0;
}

struct fraction{
	int64 num, den;
	fraction(int64 Num = 0,int64 Den = 1){
		num = Num, den = Den;
		if (den < 0){
			den = -den;
			num = -num;
		}
		int64 g = __gcd(abs(num), den);
		num /= g;
		den /= g;
	}

	bool operator <(const fraction &f) const{
		return num * f.den < f.num * den;
	}

	fraction operator +(const fraction &f) const{
		return fraction(num * f.den + den * f.num, den * f.den);
	}
};

fraction solve(point a, point &c){
	fraction ans = max(fraction( c.real(), a.real()), fraction(c.imag() ,a.imag()));
	return ans;
}

int64 det(int64 a, int64 b, int64 c, int64 d){
	return 1.0L * (a * d - b * c);
}

fraction solve(point &a, point &b, point &c){
	int64 d = det(a.real(), b.real(), a.imag(), b.imag());
	int64 dx = det(c.real(), b.real(), c.imag(), b.imag());
	int64 dy = det(a.real(), c.real(), a.imag(), c.imag());
	fraction tx = fraction(dx, d), ty = fraction(dy, d);
	return tx + ty;
}

const double eps = 1e-9, oo = numeric_limits<double>::infinity();

typedef vector<double> vec;
typedef vector<vec> mat;

double simplexMethodPD(mat &A, vec &b, vec &c)
{
	int n = c.size(), m = b.size();
	mat T(m + 1, vec(n + m + 1));
	vector<int> base(n + m), row(m);
	for(int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
			T[j][i] = A[j][i];
		T[j][n + j] = 1;
		base[row[j] = n + j] = 1;
		T[j][n + m] = b[j];
	}
	for (int i = 0; i < n; ++i)
		T[m][i] = c[i];
	while (1)
	{
		int p = 0, q = 0;
		for (int i = 0; i < n + m; ++i)
			if (T[m][i] <= T[m][p])
				p = i;
		for (int j = 0; j < m; ++j)
			if (T[j][n + m] <= T[q][n + m])
				q = j;
		double t = min(T[m][p], T[q][n + m]);
		if (t >= -eps)
		{
			vec x(n);
			for (int i = 0; i < m; ++i)
				if (row[i] < n) x[row[i]] = T[i][n + m];
			// x is the solution
			return -T[m][n + m]; // optimal
		}

		if (t < T[q][n + m])
		{
			// tight on c -> primal update
			for (int j = 0; j < m; ++j)
				if (T[j][p] >= eps)
					if (T[j][p] * (T[q][n + m] - t)
							>= T[q][p] * (T[j][n + m] - t))
						q = j;
			if (T[q][p] <= eps)
				return oo; // primal infeasible
		}
		else
		{
			// tight on b -> dual update
			for (int i = 0; i < n + m + 1; ++i)
				T[q][i] = -T[q][i];
			for (int i = 0; i < n + m; ++i)
				if (T[q][i] >= eps)
					if (T[q][i] * (T[m][p] - t)
						>= T[q][p] * (T[m][i] - t))
						p = i;
			if (T[q][p] <= eps)
				return -oo; // dual infeasible
		}
		for (int i = 0; i < m + n + 1; ++i)
			if (i != p)
				T[q][i] /= T[q][p];
		T[q][p] = 1; // pivot(q, p)
		base[p] = 1;
		base[row[q]] = 0;
		row[q] = p;
		for (int j = 0; j < m + 1; ++j)
			if (j != q)
			{
				double alpha = T[j][p];
				for (int i = 0; i < n + m + 1; ++i)
					T[j][i] -= T[q][i] * alpha;
			}
	}
	return oo;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 p, q;
	cin >> n >> p >> q;
	point c(p, q);

	vector<pair<int64,int64>> t(n);
	for (int i = 0; i < n; ++i){
		cin >> t[i].first >> t[i].second;
	}

	mat A(2, vec(n));
	vec B(2);
	vec C(n, 1.0);
	for (int i = 0; i < n; ++i){
		A[0][i] = -t[i].first;
		A[1][i] = -t[i].second;
	}
	B[0] = -p, B[1] = -q;

	double simans = simplexMethodPD(A, B, C);
	cout.precision(30);
	cout << fixed << simans << endl;
	exit(0);


	return 0;
}