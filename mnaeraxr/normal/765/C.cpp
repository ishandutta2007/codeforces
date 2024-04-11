#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef int int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;
const int mod = 1000000007;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	int tot = 0;

	for (int i = 0; i < 2; ++i){
		if (a % n){
			if (b < n){
				cout << -1 << endl;
				return 0;
			}

			b -= n;
			a -= a % n;
			tot++;
		}
		swap(a, b);
	}

	cout << tot + a / n + b / n << endl;

	return 0;
}