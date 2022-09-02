#include <iostream>

const int N = 10 + (1<<22);
// Dynamic forest
int par[N];
int cou[N];
int groups = 0;

int collapse(int i) {
	if (par[i] != i) par[i] = collapse(par[i]);
	return par[i];
}
void join(int a, int b) {
	a = collapse(a);
	b = collapse(b);
	if (a != b) {
		--groups;
		if (cou[b] > cou[a]) std::swap(a, b);
		cou[a] += cou[b];
		par[b] = a;
	}
}

bool app[N]; // app[i] = E ai : ai & i = ai
int ind[N]; // Ind of value here. -1 if none
int val[N]; // Any i : ai & i = i. -1 if none


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	int all = (1<<n) - 1;
	for (int i = 0; i < (1<<n); ++i) {
		ind[i] = -1;
		val[i] = -1;
		app[i] = false;
	}
	for (int i = 0; i < m; ++i) {
		par[i] = i;
		cou[i] = 1;
		++groups;

		int a;
		std::cin >> a;
		app[a] = true;
		ind[a] = i;
		val[all ^ a] = i;
	}
	for (int i = 0; i < (1<<n); ++i) {
		if (app[i]) {
			int oth = all ^ i;
			while(oth) {
				int bit = (oth & -oth);
				oth -= bit;
				app[i | bit] = true;
			}
		}
	}
	/*
	for (int i = 0; i <= all; ++i) {
		std::cout << i << ": ";
		for (int j = 1<<(n-1); j > 0; j >>= 1) std::cout << ((i & j) ? '1' : '0');
		std::cout << ": " << app[i] << ' ' << ind[i] << ' ' << val[i] << '\n';
	}
	*/
	for (int i = all; i >= 0; --i) {
		if (app[i] && (val[i] != -1)) {
			if (ind[i] != -1) {
				// std::cout << i << " has edge " << val[i] << ' ' << ind[i] << '\n';
				join(val[i], ind[i]);
			}
			int tmp = i;
			while(tmp) {
				int bit = (tmp & -tmp);
				tmp -= bit;
				int t = i ^ bit;
				if (app[t] && (val[t] != -1)) {
					// std::cout << t << " connects " << val[i] << ' ' << val[t] << '\n';
					join(val[i], val[t]);
				}
				val[t] = val[i];
			}
		}
	}
	std::cout << groups << '\n';
}