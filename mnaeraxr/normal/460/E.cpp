#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;
typedef complex<int> point;

int cross(const point &a, const point &b)
{
	return imag(conj(a) * b);
}

bool cmp_points_y(point a, point b){
	return make_pair(a.imag(), a.real()) < make_pair(b.imag(), b.real());
}

vector<point> convex_hull(vector<point>& P)
{
	int n = P.size(), k = 0;
	vector<point> hull(2 * n);

	sort( P.begin(), P.end(),cmp_points_y);
	// lower-hull
	for (int i = 0; i < n; hull[ k++ ] = P[ i++ ]) 
		while (k >= 2 && 
			cross( hull[k - 2]-P[i], hull[k - 1]-P[i]) <= 0) 
			--k;
	// upper-hull
	for (int i = n - 2, t = k + 1; i >= 0; hull[ k++ ] = P[ i-- ]) 
			while (k >= t && 
				cross( hull[k - 2]-P[i], hull[k - 1]-P[i]) <= 0) 
				--k;

	hull.resize(k - 1);
	return hull;
}

int sqr(int k){
	return k * k;
}

vector<point> v;
point tmp[10];
point ans[10];
int n, r, val;

int dist(point a, point b){
	return sqr(a.real() - b.real()) + sqr(a.imag() - b.imag());
}

void bt(int pos, int tot, int cval){
	if (tot == n){
		if (cval > val){
			for (int i = 0; i < n; ++i)
				ans[i] = tmp[i];
			val = cval;
		}
	}
	else{
		for (int j = pos; j < (int)v.size(); ++j){
			tmp[tot] = v[j];
			int cur = 0;
			for (int k = 0; k < tot; ++k)
				cur += dist(v[j], tmp[k]);
			bt(j, tot + 1, cval + cur);
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;

	vector<point> t;
	for (int i = -r; i <= r; ++i)
		for (int j = -r; j <= r; ++j)
			if (i * i + j * j <= r * r)
				t.push_back(point(i,j));

	v = convex_hull(t);

	val = 0;
	bt(0, 0, 0);
	cout << val << endl;
	for (int i = 0; i < n; ++i)
		cout << ans[i].real() << " " << ans[i].imag() << endl;

	return 0;
}