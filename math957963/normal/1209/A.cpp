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






int main() {
	vector<int>a;
	bool b[N];
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a.push_back(x);
		b[i] = false;
	}
	sort(a.begin(), a.end());
	f(i, n) {
		if (!b[i]) {
			ans++;
			f(j, n) {
				if (!b[j]) {
					if (a[j] % a[i] == 0)b[j] = true;
				}
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}