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
#define N 200010


int main() {
	vector<pair<char, int> >aa;
	vector<pair<char, int> >bb;
	vector<int>ans;
	int c[N];
	int d[N];
	int e[N];
	char a[N];
	char b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
		c[i] = i;
		d[i] = 0;
	}
	int n, k;
	int x, y, z;
	bool v = true;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);

	f(i, n) {
		aa.push_back(make_pair(a[i], i));
		bb.push_back(make_pair(b[i], i));
	}
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	f(i, n) {
		if (aa[i].first != bb[i].first) {
			printf("-1\n");
			return 0;
		}
		d[(bb[i].second)] = (aa[i].second);
	}
	v = true;
	f(i, n - 1) {
		x = d[i];
		y = d[i + 1];
		f(j, n) {
			if (c[j] == d[i]) {
				x = j;
				break;
			}
		}
		f(j, n) {
			if (c[j] == d[i+1]) {
				y = j;
				break;
			}
		}
		if (v) {
			ans.push_back(n - x - 1);
			f(i, n - x - 1)e[i] = c[n - i - 1];
			f(i, x + 1)e[n - x - 1 + i] = c[i];
			f(i, n)c[i] = e[i];

			f(j, n) {
				if (c[j] == d[i+1]) {
					y = j;
					break;
				}
			}

			ans.push_back(n - y - 1);
			f(i, n - y - 1)e[i] = c[n - i - 1];
			f(i, y + 1)e[n - y - 1 + i] = c[i];
			f(i, n)c[i] = e[i];

			ans.push_back(1);
			e[0] = c[n - 1];
			f(i, n - 1)e[1 + i] = c[i];
			f(i, n)c[i] = e[i];

			v = false;
		}
		else {
			ans.push_back(n - y);
			f(i, n - y)e[i] = c[n - i - 1];
			f(i, y)e[n - y + i] = c[i];
			f(i, n)c[i] = e[i];

			ans.push_back(n);
			f(i, n)e[i] = c[n - i - 1];
			f(i, n)c[i] = e[i];
			v = true;
		}
	}
	if (!v) {
		ans.push_back(n);
		f(i, n)e[i] = c[n - i - 1];
		f(i, n)c[i] = e[i];
		v = true;
	}

	printf("%d\n", ans.size());
	f(i, ans.size()) {
		printf("%d", ans[i]);
		if (i < (ans.size() - 1))printf(" ");
		else printf("\n");
	}


	return 0;
}