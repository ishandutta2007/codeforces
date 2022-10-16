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

	int n; cin >> n;

	vector<int> acc(n+1);
	vector<int> value(n);

	for (int i = 0; i < n; ++i){
		cin >> value[i];
		vector<int> freq(n+1);
		int best = 0;

		for (int j = i; j >= 0; --j){
			int v = value[j];
			freq[v]++;
			if (freq[v] > freq[best] || (freq[v] == freq[best] && v < best))
				best = v;
			acc[best]++;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << acc[i] << " ";
	cout << endl;


	return 0;
}