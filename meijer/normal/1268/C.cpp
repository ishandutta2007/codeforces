#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
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

const ll MX = 3e5;
ll n, p[MX], x[MX];
ll cntRem[MX], cntIdx[MX], cntUsed[MX];

void addFt(ll* ft, ll k, ll x) {
	for(k++; k<=n; k+=k&-k)
		ft[k] += x;
}
ll getFt(ll* ft, ll k) {
	ll ans=0;
	for(k++; k>=1; k-=k&-k)
		ans += ft[k];
	return ans;
}
ll getFt(ll* ft, ll i, ll j) {
	if(j < i) return 0;
	return getFt(ft,j)-getFt(ft,i-1);
}

void program() {
	cin>>n;
	RE(i,n) cin>>p[i];
	RE(i,n) x[p[i]-1] = i;
	RE(i,n) cntRem[i]=cntIdx[i]=cntUsed[i]=0;
	RE(i,n) addFt(cntRem, i, 1);
	RE(i,n) addFt(cntIdx, i, i);
	ll left=INF, right=-INF;
	ll ans[MX];
	ll curAns=0; 
	RE(i,n) {
		left = min(left, x[i]);
		right = max(right, x[i]);

		curAns += getFt(cntUsed, x[i], n-1);
		addFt(cntUsed, x[i], 1);

		addFt(cntRem, x[i], -1);
		addFt(cntIdx, x[i], -x[i]);

		ll lb=left, ub=right;
		while(lb != ub) {
			ll m=(lb+ub+1)/2;
			ll lCnt=m-left+1-getFt(cntRem, left, m);
			ll rCnt=right-m-getFt(cntRem, m+1, right);
			if(lCnt <= rCnt) lb=m;
			else ub=m-1;
		}
		ll mid = lb;
		ll lm = getFt(cntRem, left, mid), mr=getFt(cntRem, mid+1, right);
		ans[i]  = getFt(cntIdx, left, mid) - lm*left - lm*(lm-1)/2;
		ans[i] += mr*right - mr*(mr-1)/2 - getFt(cntIdx, mid+1, right);
		ans[i] += curAns;
	}
	RE(i,n) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
}