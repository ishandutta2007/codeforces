#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[1010]; pair<int, int> p[1010]; bool c[1010];

int main()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		scanf ("%d", &a[i]);
		p[i] = { a[i], i };
		c[i] = 0;
	}
	sort(p, p + n);

	vector<pair<int, int> > ans;
	for (int i = 0; i < n; i++){
		int s = p[i].second;
		for (int j = n - 1; j > s; j--) if (c[j]){
			ans.push_back({ s + 1,j + 1 });
		}
		c[s] = 1;
	}

	printf ("%d\n", ans.size());
	for (auto &p : ans) printf ("%d %d\n", p.first, p.second);
	return 0;
}