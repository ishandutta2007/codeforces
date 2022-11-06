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
#define N 200000

vector<int>e[N];
int used[N];
bool v;
void dfs(int k) {
	used[k] = 0;
	f(i, e[k].size()) {
		if (used[e[k][i]] == 0) {
			v = false;
			break;
		}
		else if (used[e[k][i]] == -1) dfs(e[k][i]);
	}
	used[k] = 1;
  return;
}



int main() {
	int a[N];
	int b[N];
	int n, k, m;
	int x, y, z;
	scanf("%d %d", &n, &m);
	f(i, m) {
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if (x < y)b[i] = 1;
		else b[i] = 2;
		e[x].push_back(y);
	}
	f(i, n)used[i] = -1;
	v = true;
	f(i, n) {
		if (used[i] == -1)dfs(i);
		if (!v)break;
	}
	if (v) {
		printf("1\n");
		f(i, m - 1)printf("1 ");
		printf("1\n");
	}
	else {
		printf("2\n");
		f(i, m - 1)printf("%d ",b[i]);
		printf("%d\n",b[m-1]);
	}

	return 0;
}