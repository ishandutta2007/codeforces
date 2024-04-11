#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	int nA = a + c + d;
	int nB = b + c + d;
	int sA = 0;
	int sB = 0;
	for(char x : s){
		if(x == 'A') sA++;
		if(x == 'B') sB++;
	}
	if(sA != nA || sB != nB){
		cout << "NO" << '\n';
		return;
	}

	string z;
	int plus = 0;
	vector<int> ABs;
	vector<int> BAs;

	int nboth = c + d;
	for(int i = 0; i < (int)s.size(); i++){
		z += s[i];
		if((i+1) == s.size() || z.back() == s[i+1]){
			int k = (int)z.size();
			if(k & 1){
				plus += k / 2;
			} else {
				if(z.front() == 'A'){
					ABs.push_back(k / 2);
					plus += (k-1) / 2;
				} else {
					BAs.push_back(k / 2);					
					plus += (k-1) / 2;
				}
			}
			z = "";
		}
	}
	sort(ABs.begin(), ABs.end());
	sort(BAs.begin(), BAs.end());
	for(int x : ABs){
		if(c >= x){
			c -= x;
			plus++;
		}
	}
	for(int x : BAs){
		if(d >= x){
			d -= x;
			plus++;
		}
	}
	if(plus >= nboth){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}