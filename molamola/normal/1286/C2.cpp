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

typedef vector<int> vi;

vi operator+(vi a, vi b) {
	vi c(26);
	rep(i, 26) c[i] = a[i] + b[i];
	return c;
}
vi operator-(vi a, vi b) {
	vi c(26);
	rep(i, 26) c[i] = a[i] - b[i];
	return c;
}

vector <vi> query(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int len = (r - l + 1);
	vector <vi> res;
	rep(i, len*(len+1)/2) {
		char buf[120];
		scanf("%s", buf);
		vi v(26);
		for(int a=0;buf[a];a++) v[buf[a]-'a']++;
		res.pb(v);
	}
	return res;
}

vector <pair<pii, int> > P;

int Get(vi v) {
	int res = 0;
	rep(i, 26) if(v[i] % 2) res |= 1<<i;
	return res;
}
int get_sum(vi v) {
	int s = 0;
	rep(i, 26) s += v[i];
	return s;
}

void Do(int l, int r) {
	auto v = query(l, r);
	int len = r - l + 1;
	vector <vi> L[120];
	for(auto ele : v) L[get_sum(ele)].pb(ele);
	vi S[120];
	for(int t=1;t<=(len+1)/2;t++) {
		vi sum(26);
		for(auto ele : L[t]) {
			sum = sum + ele;
		}
		S[t] = sum;
	}
	for(int t=(len+1)/2;t>1;t--) S[t] = S[t] - S[t-1];
	for(int t=1;t<(len+1)/2;t++) S[t] = S[t] - S[t+1];
	for(int t=1;t<=(len+1)/2;t++) {
		int lidx = t, ridx = len + 1 - t;
		lidx += l-1, ridx += l-1;
		P.pb({pii(lidx, ridx), Get(S[t])});
	}
}

int ans[130];

int main() {
	int n; scanf("%d", &n);
	int h = n - n / 3;
	Do(1, h);
	if(h > 1) Do(1, h-1);
	if(h < n) Do(2*h+1-n, n);
	memset(ans, -1, sizeof ans);
	rep(tt, n) {
		for(auto ele : P) {
			int x = ele.Fi.Fi, y = ele.Fi.Se, g = ele.Se;
			if(x == y) {
				ans[x] = g;
			}
			else if(ans[x] != -1) ans[y] = g ^ ans[x];
			else if(ans[y] != -1) ans[x] = g ^ ans[y];
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%c", __builtin_ctz(ans[i]) + 'a'); puts("");
	return 0;
}