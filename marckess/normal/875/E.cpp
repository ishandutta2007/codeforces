#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, LMX = 18;
int n, s1, s2, a[MX], mn[MX][LMX], mx[MX][LMX];

void obtST() {
	FORR(i,1,n) mn[i][0] = mx[i][0] = a[i];
	
	for (int j = 1; (1 << j) <= n + 1; j++)
		for (int i = 0; i + (1 << j) - 1 <= n; i++) {
			mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
			mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
		}
}

ii query (int i, int j) {
	int k = log2(j-i+1);
	return {
		min(mn[i][k], mn[j-(1<<k)+1][k]),
		max(mx[i][k], mx[j-(1<<k)+1][k])
	};
}

bool esPos (int s, int z) {
	int k = 0, l = 0;
	a[0] = s;
	
	while (k <= n) {
		if (k > l) return 0;
		
		if (k < n) {
			int i = k+1, j = n+1;
			
			while (i + 1 <= j) {
				int m = (i+j)/2;
				ii p = query(k+1, m);
				
				if (abs(a[k]-p.fi) > z || abs(a[k]-p.se) > z) j = m;
				else i = m+1;
			}
			
			l = max(l, j-1);
		}
		
		k++;
	}
	
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d %d %d", &n, &s1, &s2);
	FORR(i,1,n) scanf("%d", a+i);
	
	obtST();
	
	int i = abs(s1-s2), j = 1e9+5;
	
	while (i + 1 <= j) {
		int m = (ll(i)+j)/2;
		if (esPos(s1, m) || esPos(s2, m)) j = m;
		else i = m+1;
	}
	
	printf("%d\n", j);
	
	return 0;
}