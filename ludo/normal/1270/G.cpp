#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void run() {
	int n;
	scanf("%d", &n);
	vi v(n+1);
	for (int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		v[i] = i - x;
	}

	vector<bool> seen(n+1, false);
	int cur = 1 + (rand() % n);
	do {
		seen[cur] = true;
		cur = v[cur];
	} while (!seen[cur]);

	vi ans = { cur };
	for (int x = v[cur]; x != cur; x = v[x]) {
		ans.pb(x);
	}

	printf("%d\n", ans.size());
	for (int x : ans) printf("%d ", x);
	printf("\n");
}

int main() {
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	while (n--) run();

	return 0;
}