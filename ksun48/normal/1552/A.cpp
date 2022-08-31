#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	string t = s;
	sort(t.begin(), t.end());
	int a = 0;
	for(int i = 0; i < n; i++) if(s[i] != t[i]) a++;
	cout << a << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}