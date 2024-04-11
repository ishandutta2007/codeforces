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
#define N 500000


int main() {
	int a[N];
	set<int>st;
	map<int, int>mp;
	vector<int>b;
	vector<int>c;
	int d[N];
	int e[N];
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&k);
	f(i, n) {
		scanf("%d", &a[i]);
		if (st.count(a[i]) == 0) {
			st.insert(a[i]);
			b.push_back(a[i]);
			c.push_back(0);
		}
	}
	sort(b.begin(), b.end());
	f(i, b.size())mp[b[i]] = i;
	f(i, n) c[mp[a[i]]]++;
	k = 8 * k;
	k = k / n;
	if (k > 20) {
		printf("0\n");
		return 0;
	}
	x = 1;
	f(i, k)x = x * 2;
	k = x;
	if (b.size() <= k) {
		printf("0\n");
		return 0;
	}
	d[0] = 0;
	f(i, b.size())d[i + 1] = d[i] + c[i];
	e[n] = 0;
	for (int i = b.size() - 1; i >= 0; i--)e[i] = e[i + 1] + c[i];
	ans = n;
	f(i, b.size()-k+1) {
		s = d[i] + e[k + i];
		ans = min(ans, s);
	}

	printf("%d\n", ans);


	return 0;
}