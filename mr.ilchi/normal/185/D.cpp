/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int Que;
ll k,L,R,mod;

void MOD1(ll &x, const ll &mod) { x = x - x / mod * mod; }
ll MOD2(const ll &x, const ll &mod) { return x - x / mod * mod; }

ll go (const ll &a, ll pw, const ll &M){
	
	if (pw == 0)
		return 1;

	ll ret = 1;
	ll now = a;

	while (pw){

		if (pw & 1){
			ret = ret * now; 
			MOD1(ret,M);
		}

		now = now * now; 
		MOD1(now,M);

		pw>>=1;
	}

	return MOD2(ret,M);
}

int main(){

	scanf ("%d" , &Que);

	for (int i=1; i<=Que; i++){

		scanf ("%d %I64d %I64d %d" , &k, &L, &R, &mod);

		if (mod==2){
			printf ("%d\n" , 1 - (k&1));
			continue;
		}

		if (k==1){
			printf ("%d\n" , 2%mod);
			continue;
		}

		if (k%2 == 0){

			if (MOD2(k,mod)==0){
				printf ("1\n");
				continue;
			}

			ll base = go(k,go(2,L,mod-1),mod);

			ll ans;

			if (base==0)
				ans = 1;

			else if (base==1)
				ans = go(2,(R-L+1)%(mod-1),mod);
			else{
			   ans = go(base,go(2,R-L+1,mod-1),mod);
			   ans--;
			   ans = (ans * go(base-1,mod-2,mod)); 
			   MOD1(ans,mod);
			}

			printf ("%d\n" , (int)ans);
		}

		else{
			
			if (MOD2(k,mod)==0){
				printf ("%d\n" , go(go(2,(R-L)%(mod-1),mod),mod-2,mod));
				continue;
			}		

			ll base = go(k,go(2,L,mod-1),mod);

			ll ans;

			if (base==0)
				ans= go(go(2,(R-L)%(mod-1),mod),mod-2,mod);  
			
			else if (base==1){
				ll tmp = go(2,(R-L)%(mod-1),mod);
				ans = tmp * 2;
				ans*= go(tmp,mod-2,mod); 
				MOD1(ans,mod);
			}

			else{
			    ans = go(base,go(2,R-L+1,mod-1),mod);
				ans--; 
				ans = ans * go(base-1,mod-2,mod); MOD1(ans,mod);
				ans*= go(go(2,(R-L)%(mod-1),mod),mod-2,mod); MOD1(ans,mod);
			}

			printf ("%d\n" , (int)ans);
		}
	}

	return 0;
}