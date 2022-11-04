#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve(){
	cin >> n;
	int flag = 0;
	for(int i=1;i<=n;i++){
		int a; cin >> a;
		int b = sqrt(a);
		if(b * b != a) flag = 1;
	}
	cout << (flag ? "YES" : "NO");
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}