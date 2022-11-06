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
#define N 200010
#define MOD 998244353


int main() {
	vector<long long>b;
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d", &n, &k);
	f(i, n) {
		scanf("%I64d", &a[i]);
		if (a[i] > (n - k))b.push_back(i);
	}
	x = n;
	s = 0;
	f(i, k) {
		s += x;
		x--;
	}
	ans = 1;
	f(i, (b.size()-1)) {
		x = b[i + 1] - b[i];
		ans = (ans*x) % MOD;
	}
	printf("%I64d %I64d\n",s, ans);
return 0;
}