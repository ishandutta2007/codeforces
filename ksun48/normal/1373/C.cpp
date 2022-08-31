#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = (int)s.size();
	int cur = 0;
	int worst = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '+') cur++;
		if(s[i] == '-') cur--;
		if(cur < worst){
			ans += i+1;
			worst = cur;
		}
	}
	ans += n;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}