#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	LL a1[n], a2[n], b1[n], b2[n];
	for(int i = 0; i < n; i++) cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
	multiset<LL> good;//
	LL ans = 0;
	for(int i = 0; i < n; i++){
		if(a1[i] + b1[i] >= a2[i] + b2[i]){
			ans -= (b1[i] + b2[i]);
			good.insert(-a1[i] - b1[i]);
			good.insert(-a2[i] - b2[i]);
		}
	}
	LL turn = 1;
	while(!good.empty()){
		ans -= turn*(*good.begin());
		turn = 1-turn;
		good.erase(good.begin());
	}
	for(int i = 0; i < n; i++){
		if(a1[i] + b1[i] >= a2[i] + b2[i]) continue;
		if(a1[i] - b2[i] <= 0 && a2[i] - b1[i] >= 0) continue;
		if(a1[i] - b2[i] >= 0 && a2[i] - b1[i] >= 0){
			ans += a1[i]-b2[i];
		} else if(a1[i]-b2[i] <= 0 && a2[i] - b1[i] <= 0){
			ans += a2[i]-b1[i];
		}
	}
	cout << ans << endl;
}