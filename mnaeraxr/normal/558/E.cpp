#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e5 + 10;
const int size = 300;
const int blocks = MAXN / size + 1;
const int alph = 26;

int L[blocks][size];
int mode[blocks];
int tot[blocks][alph];

void update(int idx){
	if (mode[idx] == 0) return;
	if (mode[idx] == 1){
		for (int t = 0, p = 0; t < alph; ++t){
			for (int i = 0; i < tot[idx][t]; ++i)
				L[idx][p++] = t;
		}
	}
	else{
		for (int t = alph - 1, p = 0; t >= 0; --t){
			for (int i = 0; i < tot[idx][t]; ++i){
				L[idx][p++] = t;
			}
		}
	}
	mode[idx] = 0;
}

int f[alph];

void query(int a, int b, int k){
	memset(f, 0, sizeof f);
	int ba = a / size, pa = a % size;
	int bb = b / size, pb = b % size;

	if (ba == bb){
		update(ba);

		for (int i = pa; i <= pb; ++i)
			f[L[ba][i]]++;

		if (k == 1){
			for (int i = 0, p = pa; i < alph; ++i){
				for (int j = 0; j < f[i]; ++j)
					L[ba][p++] = i;
			}
		}
		else{
			for (int i = alph - 1, p = pa; i >= 0; --i){
				for (int j = 0; j < f[i]; ++j)
					L[ba][p++] = i;
			}
		}
	}
	else{
		update(ba); update(bb);
		for (int i = pa; i < size; ++i){
			f[L[ba][i]]++;
		}
		for (int i = 0; i <= pb; ++i){
			f[L[bb][i]]++;
		}
		for (int i = ba + 1; i < bb; ++i)
			for (int j = 0; j < alph; ++j)
				f[j] += tot[i][j];

		if (k == 1){
			for (int j = 0, p = pa; j < alph && p < size; ++j)
			for (; f[j] && p < size; ++p, --f[j]){
				tot[ba][L[ba][p]]--;
				L[ba][p] = j;
				tot[ba][L[ba][p]]++;
			}

			for (int j = alph - 1, p = pb; j >= 0 && p >= 0; --j)
			for (; f[j] && p >= 0; --p, --f[j]){
				tot[bb][L[bb][p]]--;
				L[bb][p] = j;
				tot[bb][L[bb][p]]++;
			}

			for (int i = ba + 1; i < bb; ++i){
				mode[i] = 1;
				for (int j = 0; j < alph; ++j)
					tot[i][j] = 0;
				for (int j = 0, t = 0; j < alph && t < size; ++j){
					if (f[j] + t <= size){
						tot[i][j] += f[j];
						t += f[j];
						f[j] = 0;
					}
					else{
						tot[i][j] = size - t;
						f[j] -= size - t;
						t = size;
					}
				}
			}
		}
		else{
			for (int j = alph - 1, p = pa; j >= 0 && p < size; --j)
				for (; f[j] && p < size; ++p, --f[j]){
					tot[ba][L[ba][p]]--;
					L[ba][p] = j;
					tot[ba][L[ba][p]]++;
				}

			for (int j = 0, p = pb; j < alph && p >= 0; ++j)
				for (; f[j] && p >= 0; --p, --f[j]){
					tot[bb][L[bb][p]]--;
					L[bb][p] = j;
					tot[bb][L[bb][p]]++;
				}

			for (int i = ba + 1; i < bb; ++i){
				mode[i] = -1;
				for (int j = 0; j < alph; ++j)
					tot[i][j] = 0;

				for (int j = alph - 1, t = 0; j >= 0 && t < size; --j){
					if (f[j] + t <= size){
						tot[i][j] += f[j];
						t += f[j];
						f[j] = 0;
					}
					else{
						tot[i][j] = size - t;
						f[j] -= size - t;
						t = size;
					}
				}
			}
		}
	}
}

char C[MAXN];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", C);

	for (int i = 0, b = 0, p = 0; i < n; ++i, ++p){
		if (p == size){
			p = 0;
			++b;
		}
		L[b][p] = C[i] - 'a';
		tot[b][C[i] - 'a']++;
	}

	while (q--){
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		a--; b--;
		k = k == 0 ? -1 : 1;
		query(a, b, k);
	}

	update(0);
	for (int i = 0, p = 0, b = 0; i < n; ++i, ++p){
		if (p == size){
			p = 0;
			b++;
			update(b);
		}
		putchar('a' + L[b][p]);
	}
	putchar('\n');

	return 0;
}
/*
17 2
haqqqpytcmxazcchi
1 16 1
2 15 1

19 1
jdpnptmfnskyqpznnne
4 17 0
jdp zzy tsq ppn nnm kfn e
jdp zyt sqp nmn npz kfn e
*/