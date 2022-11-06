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
#define N 301000


int main() {
	int l[N];
	int r[N];
	vector<int>aa;
	vector<int>bb;
	int n, k, t;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(i, N) {
		l[i] = -1;
		r[i] = -1;
	}
	f(tt, t) {
		scanf("%d", &n);
		aa.clear();
		bb.clear();
		f(i, n) {
			scanf("%d", &x);
			if (l[x] == -1)l[x] = i;
			r[x] = i;
			aa.push_back(x);
		}
		sort(aa.begin(), aa.end());
		bb.push_back(aa[0]);
		f(i, n - 1) {
			if (aa[i] != aa[i + 1])bb.push_back(aa[i + 1]);
		}
		k = 1;
		x = 1;
		f(i, bb.size()-1) {
			if (r[bb[i]] < l[bb[i + 1]])x++;
			else x = 1;
			k = max(k, x);
		}
		ans = bb.size() - k;
		printf("%d\n", ans);
		f(i, bb.size()) {
			l[bb[i]] = -1;
			r[bb[i]] = -1;
		}
	}
	return 0;
}