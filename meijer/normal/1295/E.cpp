#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 3e5;
int n, p[MX], a[MX], pos[MX];
ll SEG[MX*4], LAZY[MX*4];

void buildSeg(int p=0, int l=0, int r=n-1) {
	SEG	[p] = 0;
	LAZY[p] = 0;
	if(l != r) {
		int m=(l+r)/2;
		buildSeg(p*2+1,l,m);
		buildSeg(p*2+2,m+1,r);
	}
}
void addSeg(int i, int j, ll v, ll lazy=0, int p=0, int l=0, int r=n-1) {
	SEG [p] += lazy;
	LAZY[p] += lazy;
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEG [p] += v;
		LAZY[p] += v;
	} else {
		int m=(l+r)/2;
		addSeg(i,j,v,LAZY[p],p*2+1,l,m);
		addSeg(i,j,v,LAZY[p],p*2+2,m+1,r);
		SEG [p] = min(SEG[p*2+1], SEG[p*2+2]);
		LAZY[p] = 0;
	}
}
ll getSeg(int i, int j, ll lazy=0, int p=0, int l=0, int r=n-1) {
	SEG [p] += lazy;
	LAZY[p] += lazy;
	if(j < l || i > r) return 1e18;
	if(i <= l && j >= r) return SEG[p];
	int m=(l+r)/2;
	ll a=getSeg(i,j,LAZY[p],p*2+1,l,m);
	ll b=getSeg(i,j,LAZY[p],p*2+2,m+1,r);
	LAZY[p] = 0;
	return min(a, b);
}

void program() {
	cin>>n;
	RE(i,n) cin>>p[i], p[i]--;
	RE(i,n) cin>>a[i];
	RE(i,n) pos[p[i]] = i;

	buildSeg();
	RE(i,n) addSeg(i,n-1,a[i]);

	ll ans=1e18;
	RE(i,n+1) {
		ans = min(ans,getSeg(0,n-2));
		if(i != n) {
			addSeg(pos[i]	,n-1		,-a[pos[i]]);
			addSeg(0		,pos[i]-1	, a[pos[i]]);	
		}
	}
	cout << ans << endl;
}