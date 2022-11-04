#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s[3];

void solve(){
	cin >> n;
	for(int i=0;i<3;i++) cin >> s[i];

	string t = s[0];
	for(auto x : s[1]) t.push_back(x);

	for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i != j){
		int A[2] = {0, 0}, B[2] = {0, 0}, a = 0, b = 0;

		for(int k=0;k<2*n;k++) A[s[i][k]%2]++, B[s[j][k]%2]++;

		string k = "";
		while(a < 2*n || b < 2*n){
			if(s[i][a] == s[j][b]){
				k.push_back(s[i][a]);
				A[s[i][a]%2]--, B[s[j][b]%2]--;
				a++, b++;
			}else{
				if(b == 2*n || A[s[i][a]%2] > B[s[i][a]%2]){
					k.push_back(s[i][a]);
					A[s[i][a]%2]--;
					a++;
				}else{
					k.push_back(s[j][b]);
					B[s[j][b]%2]--;
					b++;
				}
			}
		}

		if(k.size() < t.size()) t = k;
	}

	cout << t;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}