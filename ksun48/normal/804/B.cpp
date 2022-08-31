#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

int main(){
	string c;
	cin >> c;
	LL ans = 0;
	LL cur = 0;
	for(int i = 0; i < c.size(); i++){
		if(c[i] == 'b'){
			ans = (ans + cur) % MOD;
		} else {
			cur = (cur + cur+1) % MOD;
		}
	}
	ans %= MOD;
	cout << ans << endl;
}