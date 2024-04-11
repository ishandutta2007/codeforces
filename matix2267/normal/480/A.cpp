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

void solve() {
	int n;
	scanf("%d",&n);
	vector<pii> V(n);
	fru(i,n) {
		scanf("%d%d",&V[i].x,&V[i].y);
	}
	sort(V.begin(), V.end());
	int day=0;
	tr(it,V) {
		if(day <= it->y) day=it->y;
		else day=it->x;
	}
	printf("%d\n", day);
}

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t=1;
	fru(i,t) solve();
	return 0;
}