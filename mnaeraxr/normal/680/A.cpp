#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<int,int> freq;

	int s = 0;

	for (int i = 0; i < 5; ++i){
		int v; cin >> v;
		freq[v] = min(freq[v] + 1, 3);
		s += v;
	}

	int a = s;

	for (auto p : freq){
		if (p.second > 1)
			a = min(a, s - p.first * p.second);
	}

	cout << a << endl;

	return 0;
}