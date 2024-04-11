#include <bits/stdc++.h>
using namespace std;

const int lim = 1000000000;

vector <int> seq;
int T;
int n;

int main()
{
	for (int i = 1; i <= 9; i++) {
		int cur = 0;
		while (cur <= lim / 10) {
			cur = 10 * cur + i;
			seq.push_back(cur);
		}
	}
	sort(seq.begin(), seq.end());
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ind = upper_bound(seq.begin(), seq.end(), n) - seq.begin();
		printf("%d\n", ind);
	}
    return 0;
}