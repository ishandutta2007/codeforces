#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, par[500500], sz[500500], odd[500500];
vector<vector<int> > input;

int find(int x)
{
	int &p = par[x];
	if (p != x) p = find(p);
	return p;
}

int main()
{
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		int k; scanf ("%d", &k);
		input.push_back({});
		while (k--){
			int x; scanf ("%d", &x); x--;
			input.back().push_back(x);
		}
	}

	for (int i = 0; i < m; i++){
		par[i] = i;
		sz[i] = 1;
	}

	for (auto &v : input){
		if (v.size() == 1){
			int x = find(v[0]);
			odd[x] = 1;
		}
		else{
			int x = find(v[0]), y = find(v[1]);
			if (x != y){
				par[y] = x;
				sz[x] += sz[y];
				odd[x] |= odd[y];
			}
		}
	}

	long long ans = 1;
	for (int i = 0; i < m; i++){
		if (par[i] == i){
			for (int k = !odd[i]; k < sz[i]; k++){
				ans = ans * 2 % 1000000007;
			}
		}
		par[i] = i;
		odd[i] = 0;
	}

	vector<int> reduce;
	for (int a = 0; a < input.size(); a++){
		auto &v = input[a];
		if (v.size() == 1){
			int x = find(v[0]);
			if (!odd[x]){
				reduce.push_back(a);
				odd[x] = 1;
			}
		}
		else{
			int x = find(v[0]), y = find(v[1]);
			if (x != y){
				if (odd[x] && odd[y]);
				else reduce.push_back(a);
				par[y] = x;
				odd[x] |= odd[y];
			}
		}
	}

	printf ("%lld %d\n", ans, reduce.size());
	for (int i = 0; i < reduce.size(); i++) printf ("%d%c", reduce[i] + 1, "\n "[i + 1 < reduce.size()]);

	return 0;
}