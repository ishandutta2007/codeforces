#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

bool isPrime(int n){
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int i = n + 1;
	while (!isPrime(i)) ++i;
	cout << (i == m ? "YES" : "NO") << endl;

	return 0;
}