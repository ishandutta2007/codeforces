#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

void end(int v){
	cout << v << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			if (v[i].first != v[j].first && v[i].second != v[j].second)
				end(abs(v[i].first - v[j].first) * abs(v[i].second - v[j].second));
		}
	}

	end(-1);

	return 0;
}