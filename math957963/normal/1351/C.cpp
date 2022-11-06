#pragma GCC optimize("O3")
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
#define M 2000000


int main() {
	char a[N];
	set<long long>st;
	f(i, N)a[i] = 0;
	int n, t;
	long long x, y;
	long long s, ans;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%s", a);
		n = strlen(a);
		x = 0;
		y = 0;
		ans = 0;
		st.clear();
		f(i, n) {
			if (a[i] == 'N') {
				s = x * M + (y * 2);
				y++;
			}
			else if (a[i] == 'S') {
				s = x * M + ((y - 1) * 2);
				y--;
			}
			else if (a[i] == 'E') {
				s = x * M + (y * 2)+1;
				x++;
			}
			else {
				s = (x - 1) * M + (y * 2) + 1;
				x--;
			}
			if (st.count(s)==1)ans += 1;
			else {
				ans += 5;
				st.insert(s);
			}
		}
		printf("%lld\n", ans);
		f(i, n + 1)a[i] = 0;
	}

	return 0;
}