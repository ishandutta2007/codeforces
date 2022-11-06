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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000

vector<long long>e[N];
long long used[N];
long long ans;

void dfs(long long  p,long long k, long long x) {
	if (used[k] >= 0&&used[k]<MOD) {
		long long y = x - used[k];
		ans = min(ans, y);
		return;
	}
	used[k] = x;
	f(i, e[k].size()) {
		if (e[k][i] != p) {
			dfs(k, e[k][i], x + 1);
		}
	}
	used[k] = MOD;
	return;
}



int main() {
	long long b[N];
	vector<long long>a[70];
	f(i, N)b[i] = 0;
	long long n, k;
	long long x, y, z;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &b[i]);
		x = b[i];
		f(j, 70) {
			if (x % 2 == 1)a[j].push_back(i);
			x = x / 2;
		}
	}
	f(i, 70) {
		if ((a[i].size()) > 2) {
			printf("3\n");
			return 0;
		}
		if (a[i].size() > 1) {
			x = a[i][0];
			y = a[i][1];
			e[x].push_back(y);
			e[y].push_back(x);
		}
	}
	ans = MOD;
	f(i, N) {
		used[i] = -1;
	}
	f(i, n) {
		if ((used[i] == -1) && (e[i].size() > 0))dfs(-2, i, 0);
	}
	if(ans!=MOD)printf("%I64d\n", ans);
	else printf("-1\n");


	return 0;
}