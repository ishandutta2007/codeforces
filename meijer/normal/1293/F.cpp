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

ll LOG2(ll _X) {return _X < 2 ? 0 : 1 + LOG2(_X/2);}

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

const ll MX = 1e6, FACTS=5005, PRIMES=700;
ll n;
ll k[MX];
ll factCnt[FACTS][PRIMES];
ll factFactors[FACTS];
ll primeNumber[FACTS], currentPrime=0;
ll sameAsPrev[FACTS];
ll cntK[FACTS];
ll sparseT[FACTS][16];

void fillPrimeNumber() {
	RE(i,FACTS) primeNumber[i] = 0;
	primeNumber[0]=primeNumber[1]=-1;
	RE(i,FACTS) {
		if(primeNumber[i] == -1) continue;
		primeNumber[i] = currentPrime++;
		for(ll j=i+i; j<FACTS; j+=i)
			primeNumber[j] = -1;
	}
}
vi primeFact(ll a) {
	vi ans;
	for(ll i=2; i*i<=a; i++) {
		while(a%i == 0) {
			a /= i;
			ans.pb(i);
		}
	}
	if(a != 1) ans.pb(a);
	return ans;
}
void fillSameAsPrev() {
	REP(i,1,FACTS) {
		REV(j,0,PRIMES) {
			if(factCnt[i][j] == factCnt[i-1][j]) {
				sameAsPrev[i] += factCnt[i][j];
			} else {
				sameAsPrev[i] += min(factCnt[i][j], factCnt[i-1][j]);
				break;
			}
		}
	}
}
void fillSparseT() {
	RE(i,FACTS)
		sparseT[i][0] = sameAsPrev[i];
	for(ll i=1; (1<<i)<=FACTS; i++) {
		for(ll j=0; j+(1<<i)-1 < FACTS; j++) {
			sparseT[j][i] = min(sparseT[j][i-1], sparseT[j+(1<<(i-1))][i-1]);
		}
	}
}
ll minSameAsPrev(ll i, ll j) {
	if(j < i) swap(i, j);
	ll k = LOG2(j-i+1);
	return min(sparseT[i][k], sparseT[j-(1<<k)+1][k]);
}
ll getEnd(ll i, ll depth) {
	ll lb=i+1, ub=FACTS-1;
	while(lb != ub) {
		ll mid=(lb+ub+1)/2;
		if(minSameAsPrev(i+1,mid) >= depth) lb = mid;
		else ub = mid-1;
	}
	if(minSameAsPrev(i+1,lb) < depth) return i;
	else return lb;
}
ll getBegin(ll i, ll depth) {
	ll lb=1, ub=i-1;
	if(ub < lb) return i;
	while(lb != ub) {
		ll mid=(lb+ub)/2;
		if(minSameAsPrev(mid+1,i) >= depth) ub = mid;
		else lb = mid+1;
	}
	if(minSameAsPrev(lb+1,i) < depth) return i;
	else return lb;
}

void program() {
	fillPrimeNumber();
	RE(i,FACTS) {
		if(i == 0) {
			RE(j,PRIMES) factCnt[i][j] = 0;
			factFactors[i] = 0;
		} else {
			RE(j,PRIMES) factCnt[i][j] = factCnt[i-1][j];
			factFactors[i] = factFactors[i-1];
			vi pFact = primeFact(i);
			for(ll v:pFact) {
				factCnt[i][primeNumber[v]]++;
				factFactors[i]++;
			}
		}
	}
	fillSameAsPrev();
	fillSparseT();

	ll tot=0;
	cin>>n;
	RE(i,n) {
		cin>>k[i];
		cntK[k[i]]++;
		tot += factFactors[k[i]];
	}
	REP(i,1,FACTS) cntK[i] += cntK[i-1];

	ll mn=0;
	REP(i,1,FACTS-1) {
		ll cnt=0;
		REP(j,1,factFactors[i]+1) {
			ll beg = getBegin(i, j);
			ll end = getEnd(i, j);
			ll dif = cntK[end]-cntK[beg-1];
			cnt -= dif;
			cnt += (n-dif);
			mn = min(mn, cnt);
			if(dif < n-dif) break;
		}
	}
	cout<<tot+mn<<endl;
}