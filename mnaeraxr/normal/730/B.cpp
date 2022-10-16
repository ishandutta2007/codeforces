#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int total;

bool ask(int a, int b){
	total--;
	cout << "? " << a << " " << b << endl;
	cout.flush();
	string s; cin >> s;
	return s == "<";
}

void ans(int a, int b){
	assert(total >= 0);
	cout << "! " << a << " " << b << endl;
	cout.flush();
}

void solve(int n){
	total = (3 * n + 1) / 2 - 2;

	if (n == 1){
		ans(1, 1);
		return;
	}

	int m = 1, M = 2;

	if (ask(M, m)) swap(m, M);

	for (int i = 3; i <= n; i += 2){
		if (i + 1 <= n){
			int a = i, b = i + 1;

			if (ask(b, a)) swap(a, b);

			if (ask(a, m)) swap(a, m);
			if (ask(M, b)) swap(b, M);
		}
		else{
			int a = i;
			if (ask(a, m)) swap(a, m);
			if (ask(M, a)) swap(a, M);
		}
	}

	ans(m, M);
}

int main(){
	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		solve(n);
	}

	return 0;
}