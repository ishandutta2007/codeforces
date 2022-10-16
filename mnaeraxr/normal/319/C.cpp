#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int MAXN = (int)1e5 + 10;
const double EPS = 1e-8;

struct Line{
	int64 m, n;
	int64 eval(int64 x){
		return m * x + n;
	}
	void print(){
		cout << m << "*x + " << n << endl;
	}
} D[MAXN]; // Deque
int B, E;

bool bad(Line l1, Line l2, Line l3){
	return 1.0 * (l1.n - l3.n) / (l3.m - l1.m) < 1.0 * (l1.n - l2.n) / (l2.m - l1.m) + EPS;
}

void insert(Line l){
	while (E - B > 1 && bad( D[E - 2], D[E - 1], l)) --E;
	D[E++] = l;
}

int64 query(int64 x){
	while (E - B > 1 && D[B].eval(x) > D[B + 1].eval(x)) ++B;
	return D[B].eval(x);
}

int64 AA[MAXN], BB[MAXN];

int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; ++i) cin >> AA[i];
	for (int i = 0; i < n; ++i) cin >> BB[i];

	int64 DP = 0;
	B = E = 0;
	insert( (Line){BB[0], 0} );

	for (int i = 1; i < n; ++i){
		DP = query( AA[i] );
		if (i + 1 != n) insert( (Line){BB[i], DP} );
	}

	cout << DP << endl;


	return 0;
}