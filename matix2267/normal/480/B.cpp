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

int n, V[MAXN];

pii find_first(int x) {
	int li=0;
	fru(ri,n) {
		while(li<n && V[li]+x<V[ri]) li++;
		if(V[li]+x == V[ri]) return pii(V[li],V[ri]);
	}
	return pii(-1,-1);
}
pii find_last(int x) {
	int ri=n-1;
	for(int li=n-1;li>=0;li--) {
		while(ri>=0 && V[li]+x<V[ri]) ri--;
		if(V[li]+x == V[ri]) return pii(V[li],V[ri]);
	}
	return pii(-1,-1);
}

void solve() {
	int l,x,y;
	scanf("%d%d%d%d",&n,&l,&x,&y);
	fru(i,n) scanf("%d",&V[i]);
	bool ox = find_first(x) != pii(-1,-1);
	bool oy = find_first(y) != pii(-1,-1);
	if(ox && oy) {
		puts("0");
		puts("");
		return;
	}
	if(ox || oy) {
		puts("1");
		if(!ox) printf("%d\n",x);
		if(!oy) printf("%d\n",y);
		return;
	}
	pii ss = find_first(x+y);
	if(ss != pii(-1,-1)) {
		puts("1");
		printf("%d\n",ss.x+x);
		return;
	}
	ss = find_first(y-x);
	if(ss != pii(-1,-1) && ss.x+y <= l) {
		puts("1");
		printf("%d\n",ss.x+y);
		return;
	}
	ss = find_last(y-x);
	if(ss != pii(-1,-1) && ss.x-x >= 0) {
		puts("1");
		printf("%d\n",ss.x-x);
		return;
	}
	puts("2");
	printf("%d %d\n",x,y);
}

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t=1;
	fru(i,t) solve();
	return 0;
}