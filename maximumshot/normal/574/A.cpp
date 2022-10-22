#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

struct SparseTable
{
	vec<int> mat[30];
	vec<int> log;

	SparseTable()
	{
		for(int i(0);i < 30;i++) mat[i].clear();
		log.clear();
	}

	SparseTable(vec<int> a)
	{
		int nn = (int)a.size() - 1, q = 0;

		mat[0].push_back(-inf);
		for(int i(1);i <= nn;i++) mat[0].push_back(a[i]);
		log.resize(nn + 1);

		while((1ll << q) <= nn) q++;
		q--;

		for(int i(nn);i >= 1;i--)
		{
			if((1ll << q) > i) q--;
			log[i] = q;
		}

		for(int i(0);i <= log[nn];i++) mat[i].resize(nn + 1, -inf);

		for(int k(1);k <= log[nn];k++) 
			for(int i(1);i <= nn;i++) 
				if(i + (1ll << (k - 1)) <= nn)
				{
					mat[k][i] = max(mat[k - 1][i], mat[k - 1][i + (1 << (k - 1))]);
				}
	}

	SparseTable(SparseTable& a)
	{
		log = a.log;
		for(int i(0);i < 30;i++) mat[i] = a.mat[i];
	}

	const SparseTable & operator = (const SparseTable& a)
	{
		log = a.log;
		for(int i(0);i < 30;i++) mat[i] = a.mat[i];
		return *this;
	}

	int get_max(int l, int r)
	{
		int len = r - l + 1;
		int LOG = log[len];
		return max(mat[LOG][l], mat[LOG][r - (1 << LOG) + 1]);
	}
};

bool solve() 
{
	int n;

	scanf("%d", &n);

	vec< int > a(n + 1);

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}

	set< pair< int, int > > s;

	for(int i = 2;i <= n;i++) s.insert(mp(a[i], i));

	int ans = 0;

	while(1) {
		int v = (--s.end())->second;
		s.erase(--s.end());
		if(a[1] > a[v]) break;
		a[1]++;
		a[v]--;
		ans++;
		s.insert(mp(a[v], v));
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}