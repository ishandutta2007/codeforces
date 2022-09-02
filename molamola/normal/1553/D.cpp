#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

char S[100010], T[100010];

void solve() {
	scanf("%s%s", S + 1, T + 1);
	int n = (int)strlen(S+1), m = (int)strlen(T + 1);
	int t = m, lst = n + 1;
	for(int i=n;i && t > 0;i--) {
		if((lst - i) % 2 == 0) continue;
		if(S[i] == T[t]) {
			--t;
			lst = i;
		}
	}
	if(t > 0) puts("NO");
	else puts("YES");
}

int main() {
	int TC; scanf("%d", &TC);
	rep(tt, TC) {
		solve();
	}
	return 0;
}