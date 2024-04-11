#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL ans = 0;
	int n;
	cin >> n;
	LL a[n];
	multiset<LL> c[3]; // neg max
	for(LL i = 0; i < n; i++){
		cin >> a[i];
	}
	for(LL i = n-1; i >= 0; i--){
		LL d = a[i];
		LL v = -1;
		if(!c[2].empty() && !c[1].empty() ){
			if(-*c[2].begin() >= -*c[1].begin()){
				v = 2;
			} else {
				v = 1;
			}
		} else if(!c[2].empty()){
			v = 2;
		} else if(!c[1].empty()){
			v = 1;
		}
		LL b = 0;
		if(v >= 0){
			if(-*c[v].begin() > a[i]){
				b = 1;
			}
		}
		if(b == 1){
			ans += (-*c[v].begin() - a[i]);
			c[v-1].insert(*c[v].begin());
			c[v].erase(c[v].begin());
			c[2].insert(-a[i]);
		} else {
			c[1].insert(-a[i]);
		}
	}
	cout << ans << endl;
}