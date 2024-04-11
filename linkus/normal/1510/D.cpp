#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int S = 22500;

int n, d;
int tab[N];
int ile[10] = {0, 0, 4, 4, 2, 1, 1, 4, 4, 2};

int main()
{
	vector<int> kub[10];
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tab[i]);
	}
	
	if (d & 1) {
		int gdzie = 1;
		for (int i = 1; i <= n; i++) {
			if (tab[i] & 1) {
				tab[gdzie] = tab[i];
				gdzie++;
			}
		}
		n = gdzie - 1;
	}
	if (d % 5 != 0) {
		int gdzie = 1;
		for (int i = 1; i <= n; i++) {
			if (tab[i] % 5 != 0) {
				tab[gdzie] = tab[i];
				gdzie++;
			}
		}
		n = gdzie - 1;
	}
	if (n == 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		kub[tab[i] % 10].push_back(tab[i]);
	}
	
	for (int i = 0; i < 10; i++) {
		sort(kub[i].begin(), kub[i].end());
	}
	
	int rest = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = ile[i]; j < kub[i].size(); j++) {
			rest = rest * i % 10;
		}
	}
	
	long double best_val = -1;
	vector<int> best_vec;
	for (int i = 0; i < S; i++) {
		int tmp = i;
		vector<int> ktore(10);
		int wsk = 0;
		while (tmp) {
			ktore[wsk] = (tmp % (ile[wsk] + 1));
			tmp /= ile[wsk] + 1;
			wsk++;
		}
		
		long double tmp_num = 0;
		int reszta = 1;
		bool ok = true;
		for (int k = 0; k < 10; k++) {
			if (ktore[k] > kub[k].size()) {
				ok = false;
				break;
			}
			
			for (int j = ktore[k]; j < min(ile[k], (int)kub[k].size()); j++) {
				reszta = reszta * k % 10;
				tmp_num += log2l(kub[k][j]);
			}
		}
		if (!ok) {
			continue;
		}
		
		if (tmp_num > best_val && rest * reszta % 10 == d) {
			best_vec = ktore;
			best_val = tmp_num;
		}
	}
	if (best_val == -1) {
		printf("-1\n");
		return 0;
	}
	
	vector<int> res;
	for (int i = 0; i < 10; i++) {
		for (int j = best_vec[i]; j < kub[i].size(); j++) {
			res.push_back(kub[i][j]);
		}
	}
	
	printf("%d\n", (int)res.size());
	for (int v : res) {
		printf("%d ", v);
	}
	printf("\n");
		
	
	
}