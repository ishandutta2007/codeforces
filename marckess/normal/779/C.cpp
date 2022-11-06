#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

int main(){
	int n, k, x;
	cin >> n >> k;

	vector<pair<int, ii> > cost(n);

	for(int i = 0; i < n; i++){
		cin >> cost[i].fi;
		cost[i].se.fi = cost[i].fi; 
	}

	for(int i = 0; i < n; i++){
		cin >> cost[i].se.se;
		cost[i].fi -= cost[i].se.se;
	}

	sort(cost.begin(), cost.end());

	int res = 0;
	for(int i = 0; i < k; i++)
		res += cost[i].se.fi;

	for(int i = k; i < n; i++)
		res += min(cost[i].se.fi, cost[i].se.se);

	cout << res;

	return 0;
}