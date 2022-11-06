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
vector<long long>e[N];
bool used[N];
long long s,ans;
long long xx[N];

long long gcd(long long x, long long y) {
	if (x > y)swap(x, y);
	if (x == 0)return y;
	if (y % x == 0)return x;
	return gcd(y%x, x);
}

void dfs(long long k,vector<pair<long long,long long> >a) {
	vector<pair<long long, long long> >b;
	map<long long,long long>mp;
	used[k] = true;
	long long s = 0;
	long long x, y, z;
	a.push_back(make_pair(xx[k], ((long long)1)));
	f(i, a.size()) {
		x = gcd(a[i].first, xx[k]);
		s = (x*a[i].second) % MOD;
		ans = (ans + s) % MOD;
		if (mp[x]>0)b[mp[x]-1].second += a[i].second;
		else {
			b.push_back(make_pair(x, a[i].second));
			mp[x] = ((long long)b.size());
		}
	}
	f(i, e[k].size()) {
		if (!used[e[k][i]]) {
			dfs(e[k][i], b);
		}
	}
	return;
}

int main() {
	long long n;
	long long x, y, z;
	vector<pair<long long, long long> >c;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &xx[i]);
	}
	f(i, n - 1) {
		scanf("%I64d %I64d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	f(i, N) {
		used[i] = false;
	}
	s = 0;
	ans = 0;
	dfs(0, c);
	printf("%I64d\n", ans);


	return 0;
}