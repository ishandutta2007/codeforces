#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define x first
#define y second
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;
typedef long long ll;
typedef double D;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;
const int P = 1000000007;

void sumpref(vi const &V, vi &W) {
	int n=V.size();
	W.resize(n);
	W[0]=V[0];
	fru(i,n) if(i) W[i] = (V[i]+W[i-1])%P;
}

void solve() {
	int n,a,b,k;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	a--; b--;
	if(a<b) n=b;
	else {
		a=n-a-1;
		b=n-b-1;
		n=b;
	}
	vi dp(n,0), dps;
	dp[a]=1;
	sumpref(dp, dps);
	fru(_,k) {
		vi dp2(n), dp2s;
		fru(i,n) {
			int upper = (i+n-1)/2;
			dp2[i] = (dps[upper] - dp[i] + P)%P;
		}
		sumpref(dp2, dp2s);
		swap(dp, dp2);
		swap(dps, dp2s);
	}
	printf("%d\n", dps.back());
}

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t=1;
	fru(i,t) solve();
	return 0;
}