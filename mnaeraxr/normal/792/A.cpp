#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> x(n);

	for (int i = 0; i < n; ++i)
		cin >> x[i];

	sort( x.begin(), x.end() );

	int len = x.back() - x[0] + 1, tot = 0;

	for (int i = 1; i < n; ++i){
		if (x[i] - x[i - 1] < len)
			tot = 0, len = x[i] - x[i - 1];

		if (x[i] - x[i - 1] == len)
			tot++;
	}

	cout << len << " " << tot << endl;


	return 0;
}