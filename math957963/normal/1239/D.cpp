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
#define N 2000010
vector<int>e[N];
int a[N];
int b[N];
int n, m;
void dfs(int k) {
	f(i, e[k].size()) {
		if (a[e[k][i]-n] == 0) {
			b[e[k][i]-n] = -1;
			a[e[k][i]-n] = 1;
			dfs(e[k][i]-n);
		}
	}
	return;
}
void dfs2(int k) {
	f(i, e[k].size()) {
		if (a[e[k][i]] == 0) {
			b[e[k][i]] = 1;
			a[e[k][i]] = -1;
			dfs2(e[k][i]+n);
		}
	}
	return;
}


int main() {
	int t;
	int x, y, z;
	bool v;
	vector<int>aa;
	vector<int>bb;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &m);
		f(i, m) {
			scanf("%d %d", &x, &y);
			x--;
			y--;
			e[x].push_back(y + n);
			e[y + n].push_back(x);
		}
		f(i, n) {
			a[i] = 0;
			b[i] = 0;
		}
		v = false;
		dfs(0);
		f(i, n) {
			if (a[i] == 0) {
				dfs2(n + i);
				v = true;
			}
		}
		if (v) {
			f(i, n) {
				if (a[i] == 1)aa.push_back(i + 1);
				else bb.push_back(i + 1);
			}
			printf("Yes\n");
			printf("%d %d\n", aa.size(), bb.size());
			f(i, aa.size()) {
				printf("%d", aa[i]);
				if (i < aa.size() - 1)printf(" ");
				else printf("\n");
			}
			f(i, bb.size()) {
				printf("%d", bb[i]);
				if (i < bb.size() - 1)printf(" ");
				else printf("\n");
			}
		}
		if (!v) {
			f(i, n) {
				a[i] = 0;
				b[i] = 0;
			}
			dfs2(n);
			f(i, n) {
				if (a[i] == 0) {
					dfs(i);
					v = true;
				}
			}
			if (v) {
				f(i, n) {
					if (a[i] == 1)aa.push_back(i + 1);
					else bb.push_back(i + 1);
				}
				printf("Yes\n");
				printf("%d %d\n", aa.size(), bb.size());
				f(i, aa.size()) {
					printf("%d", aa[i]);
					if (i < aa.size() - 1)printf(" ");
					else printf("\n");
				}
				f(i, bb.size()) {
					printf("%d", bb[i]);
					if (i < bb.size() - 1)printf(" ");
					else printf("\n");
				}
			}
		}
		if (!v) {
			printf("No\n");
		}
		aa.clear();
		bb.clear();


		f(i, 2*n)e[i].clear();
	}
	   
	return 0;
}