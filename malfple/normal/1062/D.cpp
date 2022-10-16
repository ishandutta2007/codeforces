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

int n;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#define endl '\n'
	
	cin>>n;
	ll ans = 0;
	REP(i,2,n){
		REPP(j,i+i,n,i){
			ans += j/i;
		}
	}
	cout << ans*4 << endl;
	
	return 0;
}