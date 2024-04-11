#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using t3 = tuple<int, int, int>;

int n;
char A[100010];

void solve() {
	scanf("%d%s", &n, A + 1);
	if(n == 1) {
		printf("%s%s\n", A+1, A+1);
		return;
	}
	if(A[1] <= A[2]) {
		printf("%c%c\n", A[1], A[1]);
		return;
	}
	int f = 2;
	for(int i=3;i<=n;i++) {
		if(A[i-1] >= A[i]) f = i;
		else break;
	}
	for(int i=1;i<=f;i++) printf("%c", A[i]);
	for(int i=f;i;i--) printf("%c", A[i]);
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}