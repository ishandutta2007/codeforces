#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
using namespace std;
typedef long long ll;

const int MAXM = 1000006;

const int MAXLOGN = 20;

bool visited_mul[MAXM * MAXLOGN];

int main(){
	ll n, m; cin >> n >> m;
	vector<ll> mul_quan(MAXLOGN);
	ll current_vis = 0;
	fore(i, 1, MAXLOGN){
		fore(j, 1, m+1){
			if(!visited_mul[i * j]){
				visited_mul[i * j] = 1;
				current_vis++;
			}
		}
		mul_quan[i] = current_vis;
	}
	ll res=1;
	vector<ll> vis(n + 1);
	fore(i, 2, n+1){
		if(vis[i]) continue;
		ll power = i, power_quan = 0;
		while(power <= n){
			vis[power] = 1;
			power_quan++;
			power *= i;
		}
		res += mul_quan[power_quan];
	}
	cout << res << "\n";
	
	return 0;
}