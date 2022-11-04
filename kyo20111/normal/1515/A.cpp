#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x, a[111];

void solve(){
	cin >> n >> x;
	for(int i=1;i<=n;i++) cin >> a[i];

	int sum = 0;
	for(int i=1;i<=n;i++) sum += a[i];

	if(sum == x){
		cout << "NO";
		return;
	}

	int s = 0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(s + a[i] == x){
			s += a[i+1];
			s += a[i];
			v.push_back(a[i+1]);
			v.push_back(a[i]);
			i++;
		}else{
			s += a[i];
			v.push_back(a[i]);
		}
	}

	cout << "YES\n";
	for(auto x : v) cout << x << " ";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}