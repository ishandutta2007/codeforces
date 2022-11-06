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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000
 
 
int main() {
	vector<pair<int, long long> >b;
	vector<pair<int, long long> >c;
	vector<int>d;
	vector<int>e;
	vector<long long>f;
	long long a[N];
	f(i, N)a[i] = 0;
	int n, k, m;
	int x, y;
	long long z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &m);
	f(i, m) {
		scanf("%d %d %I64d", &x,&y,&z);
		x--;
		y--;
		a[x] += z;
		a[y] -= z;
	}
	f(i, n) {
		if (a[i] > 0)b.push_back(make_pair(i + 1, a[i]));
		else if (a[i]<0)c.push_back(make_pair(i + 1, -a[i]));
	}
	x = 0;
	y = 0;
	while ((x < b.size()) && (y < c.size())) {
		if (b[x].second < c[y].second) {
			d.push_back(b[x].first);
			e.push_back(c[y].first);
			f.push_back(b[x].second);
            c[y].second -= b[x].second;
			x++;

		}
		else if (b[x].second > c[y].second) {
			d.push_back(b[x].first);
			e.push_back(c[y].first);
			f.push_back(c[y].second);
			b[x].second -= c[y].second;
			y++;
		}
		else {
			d.push_back(b[x].first);
			e.push_back(c[y].first);
			f.push_back(b[x].second);
			x++;
			y++;
		}
	}
	printf("%d\n", d.size());
	f(i, d.size()) {
		printf("%d %d %I64d\n", d[i], e[i], f[i]);
	}
 
 
	return 0;
}