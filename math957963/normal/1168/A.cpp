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
#define N 300100


int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int l,r,m;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&k);
	l = 0;
	r = k + 1;
	f(i, n) {
		scanf("%d", &a[i]);
	}
	while (l + 1 < r) {
		m = (l + r) / 2;
		m--;
		x = 0;
		v = true;
		f(i, n) {
			if ((a[i] + m) >= k) {
				if (a[i] <= x)x = x;
				else if (x <= (a[i] + m) % k)x = x;
				else x = a[i];
			}
			else {
				if (a[i] <= x && x <= a[i] + m)x = x;
				else if (x < a[i])x = a[i];
				else {
					v = false;
					break;
				}
			}
			if (!v)break;
		}
		if (v)r = m + 1;
		else l = m + 1;
	}
	printf("%d\n", l);


	return 0;
}