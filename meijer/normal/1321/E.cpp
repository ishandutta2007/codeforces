#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
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
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 3e5;
int n, m, p, a[MX], ca[MX], b[MX], cb[MX], x[MX], y[MX], z[MX];
int SA[MX], SB[MX], SX[MX], SY[MX], RX[MX];
int SEG[MX*4], LAZY[MX*4];

void addSeg(int i, int j, int x, int lazy=0, int k=0, int l=0, int r=p-1) {
	SEG [k] += lazy;
	LAZY[k] += lazy;
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEG [k] += x;
		LAZY[k] += x;
		return;
	}
	int m=(l+r)/2;
	addSeg(i,j,x,LAZY[k],k*2+1,l,m);
	addSeg(i,j,x,LAZY[k],k*2+2,m+1,r);
	SEG [k] = max(SEG[k*2+1], SEG[k*2+2]);
	LAZY[k] = 0;
}
int firstStronger(int value) {
	int lb=0, ub=p-1;
	while(lb != ub) {
		int mid=(lb+ub)/2;
		if(x[SX[mid]] >= value)	ub = mid;
		else					lb = mid+1;
	}
	return lb;
}

void program() {
	cin>>n>>m>>p;
	RE(i,n) cin>>a[i]>>ca[i];
	RE(i,m) cin>>b[i]>>cb[i];
	RE(i,p) cin>>x[i]>>y[i]>>z[i];
	x[p]=y[p]=INF; z[p]=0; p++;
	x[p]=y[p]=0; z[p]=0; p++;
	RE(i,n) SA[i]=i;
	RE(i,m) SB[i]=i;
	RE(i,p) SX[i]=i;
	RE(i,p) SY[i]=i;
	sort(SA,SA+n,[](int i, int j) {return a[i]==a[j] ? ca[i]>ca[j] : a[i]<a[j];});
	sort(SB,SB+m,[](int i, int j) {return b[i]==b[j] ? cb[i]>cb[j] : b[i]<b[j];});
	sort(SX,SX+p,[](int i, int j) {return x[i]<x[j];});
	sort(SY,SY+p,[](int i, int j) {return y[i]<y[j];});
	RE(i,p) RX[SX[i]]=i;
	REV(i,0,n-1) ca[SA[i]] = min(ca[SA[i]], ca[SA[i+1]]);
	REV(i,0,m-1) cb[SB[i]] = min(cb[SB[i]], cb[SB[i+1]]);
	RE(i,p*4) SEG[i]=LAZY[i]=0;
	REV(i,0,n) {
		int fs = 0, cost=ca[SA[i]];
		if(i != 0) fs = firstStronger(a[SA[i-1]]), cost-=ca[SA[i-1]];
		addSeg(fs,p-1,-cost);
	}
	addSeg(firstStronger(a[SA[n-1]]), p-1, -INF);
	ll ans=-2e9;
	int j=0;
	RE(i,m) {
		while(j != p && y[SY[j]] < b[SB[i]]) {
			addSeg(RX[SY[j]],p-1,z[SY[j]]);
			j++;
		}
		ans = max(ans, ll(SEG[0])-ll(cb[SB[i]]));
	}
	cout<<ans<<endl;
}