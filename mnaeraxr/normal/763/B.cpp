#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	cout << "YES" << endl;

	for (int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		cin >> x >> y;

		int c = ((x & 1) << 1) + (y & 1) + 1;
		cout << c << endl;
	}

	return 0;
}