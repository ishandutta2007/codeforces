#include<cstdio>
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
#define N 500010

long long gcd(long long x, long long y) {
	x = abs(x);
	y = abs(y);
	if (x > y)swap(x, y);
	if (x == 0)return y;
	if (y%x == 0)return x;
	return gcd(y%x, x);
}




int main() {
	vector<pair<vector<int>, long long> >aa;
	vector<int>a[N];
	long long b[N];
	int n, k, m;
	int x, y, z, t;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &m);
		f(i, n) {
			scanf("%lld", &b[i]);
		}
		f(i, m) {
			scanf("%d %d", &x, &y);
			a[y - 1].push_back(x - 1);
		}
		f(i, n) {
			if (a[i].size() > 0) {
				sort(a[i].begin(), a[i].end());
				aa.push_back(make_pair(a[i], b[i]));
			}
		}
		sort(aa.begin(), aa.end());
		s = aa[0].second;
		ans = 0;
		f(i, aa.size()-1) {
			if ((aa[i].first).size() != (aa[i + 1].first).size()) {
				ans = gcd(ans, s);
				s = aa[i + 1].second;
			}
			else if ((aa[i].first) != (aa[i + 1].first)) {
				ans = gcd(ans, s);
				s = aa[i + 1].second;
			}
			else {
				s += (aa[i + 1].second);
			}
		}
		ans = gcd(ans, s);
		printf("%lld\n", ans);
		f(i, n)a[i].clear();
		aa.clear();
	}



	return 0;
}