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
	int a[N];
	bool used[N];
	bool usedu[N];
	bool usedd[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&k);
	ans = (n * 3)- 2;
	f(i, N) {
		used[i] = false;
		usedu[i] = false;
		usedd[i] = false;
	}
	f(i, k) {
		scanf("%d", &x);
		x--;
		if (!used[x]) {
			used[x] = true;
			ans--;
		}
		if (x > 0) {
			if ((!usedu[x - 1])&&used[x-1]) {
				ans--;
				usedu[x - 1] = true;
			}
		}
		if (x < n - 1) {
			if ((!usedd[x])&&used[x+1]) {
				ans--;
				usedd[x] = true;
			}
		}
	}


	printf("%d\n", ans);


	return 0;
}