#include <bits/stdc++.h>

#define REPP(i,a,b,d) for(int i=a; i<=b; i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a; i>=b; i-=d)
#define REV(i,a,b) REVV(i,a,b,1)
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

#define pb push_back

// end of macro

const int N = 1e6 + 5;

int n;
int sieve[N];
vector<int> vec;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#define endl '\n'
	
	cin>>n;
	int ans = 1;
	int steps = 0;
	REP(i,2,n){
		if(sieve[i])continue;
		if(n%i == 0){
			ans *= i;
			int cnt = 0;
			while(n%i == 0){
				cnt++;
				n /= i;
			}
			steps = max(steps, cnt);
			vec.pb(cnt);
		}
		REPP(j,i+i,n,i)sieve[j] = 1;
	}
	int steps2 = 0, mul = 1;
	while(mul < steps){
		steps2++;
		mul *= 2;
	}
	FOR(i,vec.size()){
		if(vec[i] != mul){
			steps2++;
			break;
		}
	}
	cout << ans << " " << steps2 << endl;
	
	return 0;
}