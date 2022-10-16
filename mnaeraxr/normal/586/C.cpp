#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 4100;

int64 v[maxn], d[maxn], p[maxn];

int main(){	
	#ifdef HOME
		freopen("data.in", "r", stdin);
		// freopen("data.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i] >> d[i] >> p[i];

	vi ans;

	for (int i = 1; i <= n; ++i){
		if (p[i] < 0) continue;
		ans.push_back(i);
		int64 tot = v[i];
		int64 plus = 0;
		for (int j = i + 1; j <= n; ++j){
			if (p[j] >= 0){
				p[j] -= tot + plus;
				tot = max(0LL, tot - 1);
				if (p[j] < 0) plus += d[j];
			}
		}
	}

	cout << ans.size() << endl;
	for (auto v : ans)
		cout << v << " ";
	cout << endl;

	return 0;
}