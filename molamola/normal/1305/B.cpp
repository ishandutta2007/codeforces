#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

char buf[1010];

void solve() {
	scanf("%s", buf);
	int l = (int)strlen(buf);
	int f = -1, c = -1;
	for(int i=0;i<l;i++) {
		int c1 = 0, c2 = 0;
		for(int j=0;j<i;j++) if(buf[j] == '(') ++c1;
		for(int j=i;j<l;j++) if(buf[j] == ')') ++c2;
		if(c1 == c2) {
			if(c < c1) c = c1, f = i;
		}
	}
	vector <int> ans;
	int c1 = c, c2 = c;
	for(int j=0;j<f;j++) if(buf[j] == '(') {
		if(c1 > 0) ans.pb(j), --c1;
	}
	for(int j=f;j<l;j++) if(buf[j] == ')') {
		if(c2 > 0) ans.pb(j), --c2;
	}
	if(szz(ans) == 0) {
		puts("0");
		return;
	}
	puts("1");
	printf("%d\n", szz(ans));
	for(int e : ans) printf("%d ", e + 1);
	puts("");
}

int main() {
	int t = 1; //scanf("%d", &t);
	rep(tt, t) {
		solve();
	}
	return 0;
}