#include <bits/stdc++.h>
using namespace std;

int T;
map <int, int> M;
vector <int> seq;

int main()
{
	scanf("%d", &T);
	while (T--) {
		M.clear();
		seq.clear();
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			M[a]++;
		}
		for (auto it: M)
			seq.push_back(it.second);
		sort(seq.begin(), seq.end());
		int res = n;
		for (int i = 0; i < seq.size(); i++)
			res = min(res, n - seq[i] * (int(seq.size()) - i));
		printf("%d\n", res);
	}
    return 0;
}