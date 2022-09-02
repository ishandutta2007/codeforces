#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N;
char buf[1000010];
int Trie[1000010][26], tz;
int fail[1000010], depth[1000010];
int dp[1000010][2];

void solve() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%s", buf);
		int now = 0;
		for(int j=0;buf[j];j++) {
			int c = buf[j] - 'a';
			if(!Trie[now][c]) Trie[now][c] = ++tz;
			now = Trie[now][c];
		}
	}
	vector <int> q;
	rep(i, 26) if(Trie[0][i]) {
		int a = Trie[0][i];
		q.pb(a); fail[a] = 0; depth[a] = 1;
	}
	rep(i, szz(q)) {
		int t = q[i];
		rep(i, 26) {
			if(Trie[t][i]) {
				fail[Trie[t][i]] = Trie[fail[t]][i];
				depth[Trie[t][i]] = depth[t] + 1;
				q.pb(Trie[t][i]);
			}
			else Trie[t][i] = Trie[fail[t]][i];
		}
	}
	reverse(all(q));
	for(int i=1;i<=tz;i++) dp[i][1] = 1;
	int ans = 0;
	for(int e : q) {
		if(fail[e] && depth[e] == depth[fail[e]] + 1) {
			int f = fail[e];
			dp[f][0] += max(dp[e][0], dp[e][1]);
			dp[f][1] += dp[e][0];
		}
		else ans += max(dp[e][0], dp[e][1]);
	}
	
	printf("%d\n", ans);
	
	for(int i=0;i<=tz;i++)  {
		fail[i] = depth[i] = 0;
		dp[i][0] = dp[i][1] = 0;
		rep(j, 26) Trie[i][j] = 0;
	}
	tz = 0;
}

int main() {
	int T; scanf("%d", &T);
	for(int tc=1;tc<=T;tc++) {
		solve();
	}
	return 0;
}