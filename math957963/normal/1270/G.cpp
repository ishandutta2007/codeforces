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
#define N 1001000
int e[N];
int used[N];
bool dfs(int k) {
	bool re;
	if (used[k] > 0) {
		used[k] = 2;
		return true;
	}
	used[k] = 1;
	re = dfs(e[k]);
	if (re) {
		if (used[k] > 1)return false;
		else {
			used[k] = 2;
			return true;
		}
	}
	else return false;

}



int main() {
	vector<int>b;
	int n, k;
	int t;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, n) {
			scanf("%d", &x);
			e[n - i - 1] = x + n - i - 1;
		}
		f(i, n)used[i] = 0;
		dfs(0);
		b.clear();
		f(i, n)if (used[i] > 1)b.push_back(n - i);
		printf("%d\n", b.size());
		f(i, b.size()) {
			printf("%d", b[i]);
			if (i < (b.size() - 1))printf(" ");
			else printf("\n");
		}
	}


	return 0;
}