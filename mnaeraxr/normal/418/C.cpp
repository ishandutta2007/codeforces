#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

#define rep(i, n) for (int i = 1; i <= n; ++i)

int64 nextsquare(int64 v){
	int64 t = 1;

	while (t * t <= v)
		t += 1;

	return t;
}

int64 top = 1000;

set<int64> square;
int64 last;

bool issquare(int64 v){
	while (last * last <= v){
		square.insert( last * last );
		last++;
	}

	return square.count(v);
}



bool solve(int64 n, int64 m){
	int64 sum;
	for (int64 t = 1; t <= top; ++t){
		sum = t * t + n - 1;

		if (!issquare(sum)) continue;

		for (int64 p = 1; p <= top; ++p){
			sum = p * p + m - 1;
			if (!issquare(sum)) continue;

			for (int64 v = 1; v <= top; ++v){
				cout << t << " "<< p << " " << v << endl;

				int64 x1 = (m - 1) * t * t + v * v;
				int64 x2 = (n - 1) * p * p + v * v;

				if (issquare(x1) && issquare(x2)){

					for (int i = 0; i < n - 1; ++i){
						for (int j = 0; j < m - 1; ++j)
							cout << 1 << " ";
						cout << t << endl;
					}

					for (int j = 0; j < m - 1; ++j)
						cout << p << " ";

					cout << v << endl;
					exit(0);

					return true;
				}
			}
		}
	}

	return false;
}

int64 s(int64 v){
	return v * v;
}

int64 get(int64 a, int64 n){
	if (n == 1) return 1;
	if (n == 2){
		if (a == 0) return 3;
		if (a == 1) return 4;
	}

	if (a + 2 < n) return 1;
	if (a + 1 == n){
		if (n & 1) return (n + 1) / 2;
		else return (n - 2) / 2;
	}

	if (n & 1) return 2;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout << get(i, n) * get(j, m) << " ";
		}
		cout << endl;
	}



	return 0;
}