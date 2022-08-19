#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, k;
	cin >> n >> k;
	LL c[n];
	for(LL i = 0; i < n; i++){
		cin >> c[i];
	}
	set<pair<LL,LL> > st;
	for(LL i = 0; i < k; i++){
		st.insert(make_pair(-c[i], i));
	}
	map<LL,LL> best;
	for(LL i = k; i < k+n; i++){
		if(i < n) st.insert(make_pair(-c[i], i));
		pair<LL,LL> r = *st.begin();
		st.erase(st.begin());
		best[r.second] = i+1;
	}
	LL ans = 0;
	for(LL i = 0; i < n; i++){
		ans += c[i] * (best[i] - (i+1));
	}
	cout << ans << endl;
	for(LL i = 0; i < n; i++){
		cout << best[i] << " ";
	}
	cout << endl;
}