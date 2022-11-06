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
#define N 200010


int main() {
	bool used[N];
	int a[N];
	vector<int>cc;
	vector<int> p;
	vector<int>xx;
	int n, k, q, m;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		cc.push_back(1);
		p.push_back(i);
		xx.push_back(x);
		used[i] = false;
	}
	scanf("%d", &q);
	f(qq, q) {
		scanf("%d", &x);
		if (x == 1) {
			scanf("%d %d", &y, &z);
			y--;
			cc.push_back(1);
			p.push_back(y);
			xx.push_back(z);
		}
		else {
			scanf("%d", &y);
			cc.push_back(2);
          	p.push_back(n);
			xx.push_back(y);
		}
	}
	m = -1;
	for(int i=cc.size()-1;i>=0;i--) {
		if (cc[i] == 2) {
			m = max(m, xx[i]);
		}
		else {
			if (!used[p[i]]) {
				a[p[i]] = max(m, xx[i]);
				used[p[i]] = true;
			}
		}
	}

	f(i, n) {
		printf("%d", a[i]);
		if (i < n - 1)printf(" ");
		else printf("\n");
}


	return 0;
}