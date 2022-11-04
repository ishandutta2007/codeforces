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
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef complex<double> point;

ll n,k;
ll fact[50];
vector <ll> Q;

inline vector <ll> find (int n , ll num){
	
	bool mark[100]; memset (mark , false, sizeof mark);

	num--;

	vector <ll> ret;

	for (int i=n-1; i>=0; i--){

		int cnt=1;

		for (int j=1; j<=n; j++) if (!mark[j]){
			
			if (cnt * fact[i] <= num){
				cnt++;
			}

			else{
				num-= (cnt-1) * fact[i];
				ret.push_back (j); mark[j] = true; break;
			}
		}	
	}

	return ret;
}

inline void go (int pos , ll val){
	
	if (pos!=0)
		Q.push_back (val);

	if (pos==10)
		return;

	go (pos+1, val*10 + 4);
	go (pos+1, val*10 + 7);
}

int main(){

	go (0,0ll); sort(Q.begin() , Q.end());

	fact[0] = 1;

	for (int i=1; i<=20; i++)
		fact[i] = fact[i-1] * (ll)i;

	cin >> n >> k;

	ll ans = 0;

	for (int o=1; true; o++) if (fact[o]>=k){
		
		if (o > n){
			cout << -1 << endl;
			return 0;
		}

		int pos = upper_bound (Q.begin() , Q.end() , n-o) - Q.begin();

		ans+= pos;

		vector <ll> per = find(o,k);

		for (int i=0; i<(int)per.size(); i++){
			
			int p1 = lower_bound (Q.begin() , Q.end() , per[i] + n-o) - Q.begin();
			int p2 = lower_bound (Q.begin() , Q.end() , i + n-o+1) - Q.begin();

			if (Q[p1] == per[i] + n-o && Q[p2] == i+n-o+1)
				ans++;
		}

		break;
	}

	cout << ans << endl;

	return 0;
}