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
#define N 400010






int main() {
	vector<int>a;
	vector<pair<int,int> >b;
	vector<int>d;
	vector<int>c;
	vector<vector<int>>cc;
	vector<int>e;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	k = 1;
	f(i, n-1) {
		if (a[i + 1] != a[i]) {
			b.push_back(make_pair(k, a[i]));
			k = 1;
		}
		else k++;
}
	b.push_back(make_pair(k, a[n-1]));
	sort(b.begin(), b.end(), greater<pair<int, int> >());
	x = n;
	d.push_back(x);
	f(i, b.size()) {
		x = x - b[i].first;
		d.push_back(x);
	}
	ans = 1;
	z = 1;
	for (int i = 1; (i*i) <= n; i++) {
		s = 0;
		f(j, b.size()) {
			if (b[j].first > i)s += i;
			else {
				s += d[j];
				break;
			}
		}
		if (s >= (i*i)) {
			x = s / i;
			if (ans < (x*i)) {
				ans = (x*i);
				z = i;
			}
		}
}
	x = 0;
	k = 0;
	while (k < ans) {
		if (b[x].first > z) {
			y = b[x].second;
			f(i, z) {
				if(k < ans) {
					e.push_back(y);
					k++;
				}
			}
		}
		else {
			f(i, b[x].first) {
				y = b[x].second;
				if (k < ans) {
					e.push_back(y);
					k++;
				}
			}
		}
		x++;
	}
	y = ans / z;
	f(i, y)c.push_back(0);
	f(i, z)cc.push_back(c);
	f(i, y) {
		f(j, z) {
			x = (i + j) % y;
			cc[j][x] = e[(i*z) + j];
		}
	}
	printf("%d\n", ans);
	printf("%d %d\n", z, y);
	f(i, z) {
		f(j, y) {
			printf("%d", cc[i][j]);
			if (j < (y - 1))printf(" ");
		}
		printf("\n");
	}


	return 0;
}