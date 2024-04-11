#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;

void solve(){
	cin >> n >> s;

	if(s[0] == '0' || s[n-1] == '0'){
		cout << "NO";
		return;
	}

	int cnt = 0;
	for(int i=0;i<n;i++) cnt += s[i] == '0';

	if(cnt % 2){
		cout << "NO";
		return;
	}

	cout << "YES\n";

	for(int i=0,j=0,k=0;i<n;i++){
		if(s[i] == '0'){
			if(k % 2) cout << "(";
			else cout << ")";
			k++;
		}else{
			if(++j <= (n - cnt) / 2) cout << "(";
			else cout << ")";
		}
	}
	cout << "\n";

	for(int i=0,j=0,k=0;i<n;i++){
		if(s[i] == '0'){
			if(k % 2) cout << ")";
			else cout << "(";
			k++;
		}else{
			if(++j <= (n - cnt) / 2) cout << "(";
			else cout << ")";
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}