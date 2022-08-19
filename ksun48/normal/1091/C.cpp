#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	set<LL> ans;
	for(LL d = 1; d * d <= n; d++){
		if(n % d != 0) continue;
		LL v = d;
		ans.insert(v + n*(v-1) / 2);
		v = n/d;
		ans.insert(v + n*(v-1) / 2);
	}
	for(LL x : ans){
		cout << x << endl;
	}
}