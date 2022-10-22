#include <bits/stdc++.h>
using namespace std;

const int Maxd = 6;

int pw[Maxd];
map <int, set <int> > M[Maxd];
set <int> tmp;

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxd; i++)
		pw[i] = pw[i - 1] * 10;
	for (int i = 1; i < Maxd; i++) {
		for (int j = 0; j < pw[i]; j++)
			M[i][j].insert(j);
		for (int a = 1; a < i; a++) {
			int b = i - a;
			for (auto it1: M[a])
				for (auto it2: M[b])
					for (auto it3: it1.second)
						for (auto it4: it2.second) {
							int num = it3 * pw[b] + it4;
							if (a <= b) {
							    if (M[i][it1.first + it2.first].size() < 2000)
								    M[i][it1.first + it2.first].insert(num);
								if (M[i][it1.first * it2.first].size() < 2000)
								    M[i][it1.first * it2.first].insert(num);
							}
							if (M[i][it1.first - it2.first].size() < 2000)
							    M[i][it1.first - it2.first].insert(num);
						}
		}
	}
	int n, lim; scanf("%d %d", &n, &lim);
	for (int a = 3; a <= 5 && tmp.size() < lim; a++) {
		int b = 8 - a;
		for (auto it1: M[a]) {
			if (tmp.size() >= lim) break;
			for (auto it2: it1.second) {
				if (tmp.size() >= lim) break;
				// +
				auto it3 = M[b].find(n - it2);
				if (it3 != M[b].end())
					for (auto it4: it3->second) {
						if (tmp.size() >= lim) break;
						tmp.insert(it2 * pw[b] + it4);
					}
				// -
				it3 = M[b].find(it2 - n);
				if (it3 != M[b].end())
					for (auto it4: it3->second) {
						if (tmp.size() >= lim) break;
						tmp.insert(it2 * pw[b] + it4);
					}
				// *
				if (it2 != 0 && n % it2 == 0) {
					it3 = M[b].find(n / it2);
					if (it3 != M[b].end())
						for (auto it4: it3->second) {
							if (tmp.size() >= lim) break;
							tmp.insert(it2 * pw[b] + it4);
						}
				}
			}
		}
	}
	for (auto it: tmp)
		printf("%08d\n", it);
    return 0;
}