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
	set<int> a[N];
	vector<int>aa[N];
	vector<int>b;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n-1; i++) {
		if (n%i == 0)b.push_back(i);
	}
	f(i, k) {
		scanf("%d %d", &x, &y);
		x--;
		y--;
		z = (y - x + n) % n;
		a[x].insert(z);
		aa[x].push_back(z);
		z = (x - y + n) % n;
		a[y].insert(z);
		aa[y].push_back(z);
	}
	f(i, b.size()) {
		v = true;
		f(j, n) {
			x = (j + b[i]) % n;
			f(ii, aa[j].size()) {
				if (a[x].count(aa[j][ii]) == 0) {
					v = false;
					break;
				}
			}
			if (!v)break;
		}
		if (v)break;
	}
	

	if(v)printf("Yes\n");
	else printf("No\n");


	return 0;
}