#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int bits = 500;

typedef bitset<bits> B;

const int64 oo = 1000000000000000000LL;
const double eps = 1e-9;
const int maxn = 70;

struct matrix{
	int n;
	vector<B> row;
	vector<B> col;

	matrix(int n) : n(n){
		row = vector<B>(n);
		col = vector<B>(n);
	}

	void set(int x, int y, int v=1){
		row[x][y] = v;
		col[y][x] = v;
	}

	matrix operator *(const matrix &m) const{
		matrix ans(n);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ans.set(i, j, (row[i] & m.col[j]).any());

		return ans;
	}

	bool ok(){
		return col[0].any();
	}

	void print(){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				cout << row[i][j];
			cout << endl;
		}
		cout << endl;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	matrix P(n), V(n);

	for (int i = 0; i < m; ++i){
		int u, v, t;
		cin >> u >> v >> t;

		u--; v--;

		if (t == 0) P.set(v, u);
		else V.set(v, u);
	}

	vector<pair<matrix,matrix>> R(1, {P, V});
	vector<int64> length(1, 1);

//	P.print();
//	V.print();
//
//	cout << P.ok() << endl;

	while (R.back().first.ok() && length.back() <= oo){
//		cout << "here" << endl;

		int64 nlength = length.back() * 2;
		length.push_back( nlength );

		matrix A = R.back().second * R.back().first;
		matrix B = R.back().first * R.back().second;

		R.push_back({A, B});

//		A.print();
//		B.print();
//		cout << A.ok() << endl;
	}

//	cout << R.size() << endl;

	if (R.back().first.ok() && length.back() > oo){
		cout << -1 << endl;
		return 0;
	}

	matrix current(n);

	for (int i = 0; i < n; ++i)
		current.set(i, i);

	int64 answer = 0;

	int p = R.size() - 2;
	int a = 0;

	while (p >= 0){
		matrix &lev = (a == 0 ? R[p].first : R[p].second);
		matrix test = lev * current;

		if (test.ok()){
			current = test;
			answer += length[p];
			a ^= 1;
		}

		p--;
	}

	if ( answer > oo ) cout << -1 << endl;
	else cout << answer << endl;

	return 0;
}