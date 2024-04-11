#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
void solve(long long N, long long L, long long T, vector<long long> X, vector<long long> W, vector<ll> origidx){
	vector<pll> v;
	ll sumtimes=0;
	for (ll i=1;i<N;i++) {
		if (W[i]!=W[0]) {
			ll diff;
			if (W[0]==1) {diff=(X[i]-X[0]+L)%L;}
			else {diff=(X[0]-X[i]+L)%L;}
			if (diff<0) diff+=L;
			ll times=(max(0ll,(2*T+L-diff+(W[0]==1?-1:0))/L))%N;
			//printf("diff:%lld times:%lld i:%lld\n",diff,times,i);
			if (W[0]!=1) times=N-times;
			assert(times>=0);
			sumtimes+=times;
			sumtimes%=N;
		}
	}
	for (ll i=0;i<N;i++) {
		ll dir=W[i]==1?1:-1;
		v.PB(MP(((X[i]+dir*T)%L+L)%L,i));
	}
	sort(v.begin(),v.end());
	ll antForLineZero=sumtimes;
	//printf("aflz:%lld\n",antForLineZero);
	ll newZeroIdx=-1;
	for (ll i=0;i<N;i++) {
		if (v[i].snd==0) {newZeroIdx=i; break;}
	}
	if (W[antForLineZero]==1) {
		if (newZeroIdx!=0&&v[newZeroIdx]==v[(newZeroIdx-1)]) {
			newZeroIdx=(newZeroIdx-1);
		}
	}
	else if (W[antForLineZero]==2) {
		if (newZeroIdx!=N&&v[newZeroIdx]==v[(newZeroIdx+1)]) {
			newZeroIdx=(newZeroIdx+1);
		}
	}
	vector<ll> vans;
	vans.resize(N);
	for (ll i=0;i<N;i++) {
		vans[origidx[(antForLineZero+i)%N]]=v[(newZeroIdx+i)%N].fst;
	}
	for (ll i=0;i<N;i++) {
		ll ans=vans[i]+1;
		printf("%lld ",vans[i]+1);
	}
	printf("\n");
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long T;
	long long N;
	long long L;
	scanf("%lld",&N);
	vector<long long> W(N-1+1);
	vector<long long> X(N-1+1);
	vector<long long> origidx(N-1+1);
	scanf("%lld",&L);
	scanf("%lld",&T);
	vector<pair<pll,ll> > v(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		char c;
		ll x;
		scanf("%lld %c",&x,&c);
		--x;
		v[i].fst.fst=x;
		v[i].fst.snd=(c=='R')?1:2;
		v[i].snd=i;
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i <= N-1 ; i++){
		X[i]=v[i].fst.fst;
		W[i]=v[i].fst.snd;
		origidx[i]=v[i].snd;
	}
	solve(N, L, T, X, W,origidx);
	return 0;
}