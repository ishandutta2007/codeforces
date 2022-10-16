#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;


int M[30][30];
int T[30][30];

bool check(int n, int m){
	for (int i = 0; i < n; ++i){
		int counter = 0;
		for (int j = 0; j < m; ++j)
			if (T[i][j] != j + 1) counter += 1;
		if (counter > 2) return false;
	}

	return true;
}

void vcopy(int n, int m){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			T[i][j] = M[i][j];
}

void vswap(int n, int m, int i, int j){
	for (int k = 0; k < n; ++k)
		swap(T[k][i], T[k][j]);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> M[i][j];
			T[i][j] = M[i][j];
		}
	}

	if (check(n, m)){
		cout << "YES" << endl;
		exit(0);
	}


	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j){
			vcopy(n, m);
			vswap(n, m, i, j);

			if (check(n, m)){
				cout << "YES" << endl;
				exit(0);
			}
		}

	cout << "NO" << endl;

	return 0;
}