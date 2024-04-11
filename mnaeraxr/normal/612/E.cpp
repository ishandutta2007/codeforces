#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;

int perm[maxn];
int ans[maxn];
bool seen[maxn];
int lst[maxn];

int get(int p){
	int pnt = 0;
	while (!seen[p]){
		lst[pnt++] = p;
		seen[p] = true;
		p = perm[p];
	}
	return pnt;
}

void fix(int p, int size){
	for (int i = 0; i < size; ++i)
		ans[lst[i]] = lst[(i + (size+1) / 2) % size];
}

void merge(int p1, int p2, int size){
	for (int i = 0; i < size; ++i){
		ans[p1] = p2;
		p1 = perm[p1];
		ans[p2] = p1;
		p2 = perm[p2];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> perm[i];

	map<int,int> mm;
	int tot = 0;
	for (int i = 1; i <= n; ++i) if (!seen[i]) {
		int sz = get(i);

		if (sz & 1)
			fix(i, sz);
		else{
			if (mm[sz] != 0){
				merge(mm[sz], i, sz);
				mm[sz] = 0;
				--tot;
			}
			else{
				mm[sz] = i;
				++tot;
			}
		}
	}

	if (tot == 0)
	{
		for (int i = 1; i <= n; ++i)
			cout << ans[i] << " ";
		cout << endl;
	}
	else{
		cout << -1 << endl;
	}

	return 0;
}