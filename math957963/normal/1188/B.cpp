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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000
map<long long, long long>mp;
set<long long>st;
vector<long long>vec;

int main() {
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k, p;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d %I64d", &n, &p, &k);
	f(i, n) {
		scanf("%I64d", &x);
		y = (k*x) % p;
		x = (x*x) % p;
		x = (x*x) % p;
		x = (x - y + p) % p;
		if (st.count(x) == 1)mp[x] = mp[x] + 1;
		else {
			vec.push_back(x);
			st.insert(x);
			mp[x] = 1;
		}
	}
	f(i, vec.size()) {
		x = mp[vec[i]];
		y = (x * (x - 1)) / 2;
		ans += y;
	}
	printf("%I64d\n", ans);


	return 0;
}