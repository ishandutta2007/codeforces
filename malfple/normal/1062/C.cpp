#include <bits/stdc++.h>

#define REPP(i,a,b,d) for(int i=a; i<=b; i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a; i>=b; i-=d)
#define REV(i,a,b) REVV(i,a,b,1)
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

#define pb push_back

typedef long long ll;

// end of macro

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
	return (a+b)%MOD;
}
inline ll submod(ll a, ll b){
	return (MOD+a-b)%MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}

const int N = 1e5 + 5;

int n,m;
string str;
int pf[N];
int pow2[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#define endl '\n'
	
	pow2[0] = 1;
	REP(i,1,N-5)pow2[i] = mulmod(pow2[i-1], 2);
	
	cin>>n>>m;
	cin>>str;
	FOR(i,str.size()){
		if(str[i] == '0')pf[i+1] = 1;
		pf[i+1] += pf[i];
	}
	REP(i,1,m){
		int l,r;
		cin>>l>>r;
		int nt = r-l+1;
		int n0 = pf[r] - pf[l-1];
		cout << submod(pow2[nt], pow2[n0]) << endl;
	}
	
	return 0;
}