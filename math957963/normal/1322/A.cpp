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
#define N 1000010


int main() {
	vector<int>b;
	vector<int>c;
	bool d[N];
	char a[N];
	f(i, N) {
		a[i] = 0;
		d[i] = false;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	
	f(i, n) {
		if (a[i] == '(')b.push_back(i);
		else c.push_back(i);
	}
	if (b.size() != c.size()) {
		printf("-1\n");
		return 0;
	}
	if (c[0] < b[0]) {
		for (int i = c[0]; i <= b[0]; i++)d[i] = true;
	}
	for (int i = 1; i < b.size(); i++) {
		if (c[i] < b[i]) {
			if (b[i - 1] > c[i]) {
				for (int j = b[i - 1] + 1; j <= b[i]; j++)d[j] = true;
			}
			else {
				for (int j = c[i]; j <= b[i]; j++)d[j] = true;
			}
		}
	}
	f(j, N)if (d[j])ans++;
	printf("%d\n", ans);


	return 0;
}