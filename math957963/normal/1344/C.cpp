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
#define N 300010
vector<int>e1[N];
vector<int>e2[N];
int used[N];
int used2[N];
bool v;
void dfs(int k) {
	used[k] = 2;
	int sz = e1[k].size();
	f(i, sz) {
		if (used[e1[k][i]] == 2) {
			v = false;
			return;
		}
		else if (used[e1[k][i]] == 0)dfs(e1[k][i]);
		if (!v)return;
	}
	used[k] = 1;
	return;
}

void dfs1(int k) {
	used[k] = 1;
	int sz = e1[k].size();
	f(i, sz) {
		if (used[e1[k][i]] == 0)dfs1(e1[k][i]);
	}
	return;
}
void dfs2(int k) {
	used2[k] = 1;
	int sz = e2[k].size();
	f(i, sz) {
		if (used2[e2[k][i]] == 0)dfs2(e2[k][i]);
	}
	return;
}


int main() {
	int a[N];
	char ans[N];
	f(i, N) {
		a[i] = 0;
		ans[i] = 0;
	}
	int n, m, k;
	int x, y, z;
	int s;
	scanf("%d %d", &n, &m);
	f(i, m) {
		scanf("%d %d", &x, &y);
		e1[x-1].push_back(y-1);
		e2[y-1].push_back(x-1);
	}
	f(i, n) {
		used[i] = 0;
	}
	v = true;
	f(i, n) {
		if (used[i] == 0) {
			dfs(i);
			if (!v)break;
		}
	}
	if (!v) {
		printf("-1\n");
		return 0;
	}
	f(i, n) {
		used[i] = 0;
		used2[i] = 0;
	}
	s = 0;
	f(i, n) {
		ans[i] = 'E';
		if ((used[i] == 0)&&(used2[i]==0)) {
			ans[i] = 'A';
			s++;
		}
			dfs1(i);
			dfs2(i);
	}

	printf("%d\n", s);
	printf("%s\n", ans);

	return 0;
}