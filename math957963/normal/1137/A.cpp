#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 1010
	vector<pair<int,int> >a[N];
	vector<pair<int,int> >b[N];
	int c[N][N];
	int d[N][N];




int main() {

	int n, m, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &m);
	f(i, n) {
		f(j, m) {
			scanf("%d", &x);
			a[i].push_back(make_pair(x, j));
			b[j].push_back(make_pair(x, i));
		}
	}
	f(i, n) {
		sort(a[i].begin(), a[i].end());
		k = 1;
		f(j, m-1) {
			if (a[i][j].first != a[i][j + 1].first)k++;
		}
		x = 1;
		c[i][a[i][0].second] = x - 1;
		d[i][a[i][0].second] = k - x;
		f(j, m - 1) {
			if (a[i][j].first != a[i][j + 1].first)x++;
			c[i][a[i][j+1].second] = x - 1;
			d[i][a[i][j+1].second] = k - x;
		}
	}
	f(i, m) {
		sort(b[i].begin(), b[i].end());
		k = 1;
		f(j, n - 1) {
			if (b[i][j].first != b[i][j + 1].first)k++;
		}
		x = 1;
		c[b[i][0].second][i] = max(c[b[i][0].second][i],x - 1);
		d[b[i][0].second][i] = max(d[b[i][0].second][i],k - x);
		f(j, n - 1) {
			if (b[i][j].first != b[i][j + 1].first)x++;
			c[b[i][j+1].second][i] = max(c[b[i][j+1].second][i], x - 1);
			d[b[i][j+1].second][i] = max(d[b[i][j+1].second][i], k - x);
		}
	}
	f(i, n) {
		f(j, m) {
			printf("%d", c[i][j] + d[i][j] + 1);
			if (j < (m - 1))printf(" ");
		}
		printf("\n");
	}

	return 0;
}