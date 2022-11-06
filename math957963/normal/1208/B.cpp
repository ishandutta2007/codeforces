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
	set<int>s;
	int n, k;
	int x, y, z;
	int ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	f(i, n+1) {
		s.clear();
		v = true;
		k = 0;
		f(j, i) {
			if (s.count(a[j]) != 0) {
				v = false;
				break;
			}
			s.insert(a[j]);
			k++;
		}
		if (v) {
			f(j, n - i) {
				if (s.count(a[n-j-1]) != 0)break;
				s.insert(a[n-j-1]);
				k++;
			}
			ans = max(ans, k);
		}
	}
	ans = n - ans;
	printf("%d\n", ans);
	return 0;
}