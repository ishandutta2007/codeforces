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
	vector<int>b;
	int n, x, t;
	bool v;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		b.clear();
		f(i, n) {
			scanf("%d", &x);
			if (x < 0) {
				x = -x;
				x = x % n;
				x = (n - x) % n;
			}
			else x = x % n;
			x = (x + i) % n;
			b.push_back(x);
		}
		v = true;
		sort(b.begin(), b.end());
		f(i, n-1) {
			if (b[i] == b[i + 1])v = false;
		}
		if (v)printf("YES\n");
		else printf("NO\n");		
	}

	return 0;
}