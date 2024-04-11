#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;
vector <int> seq;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		string s; cin >> s;
		seq.clear();
		for (int i = 0; i < n; i++)
			if (s[i] == '*') seq.push_back(i);
		int res = 1;
		int lst = seq[0];
		while (lst < seq.back()) {
			int nxt = upper_bound(seq.begin(), seq.end(), lst + k) - seq.begin() - 1;
			res++;
			lst = seq[nxt]; 
		}
		printf("%d\n", res);
	}
    return 0;
}