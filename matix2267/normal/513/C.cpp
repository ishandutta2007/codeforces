#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 10004;

int L[10], R[10];

void solve() {
	int n;
	scanf("%d",&n);
	fru(i,n) scanf("%d%d",&L[i],&R[i]);
	D ev = 0.0;
	fru(i,n) fru(j,n) if(i!=j) fru(h, MAXN) {
		// i wygrywa, j jest drugi i ma wartosc h
		if(h < L[j] || h > R[j]) continue;
		int ico = R[i] - max(h + (i>j), L[i]) + 1;
		if(ico <= 0) continue;
		D prob = ico;
		fru(k,n) if(i!=k && j!=k) {
			int kco = min(R[k], h - (k<j)) - L[k] + 1;
			if(kco <= 0) goto lab;
			prob *= kco;
		}
		ev += prob * h;
lab:
		;
	}
	fru(i,n) ev /= R[i]-L[i]+1;
	printf("%.15lf\n", ev);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}