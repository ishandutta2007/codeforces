#include <iostream>
#define llint long long

using namespace std;

string s;
llint Q;
llint sum[26][200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> Q;
	llint n = s.size();
	s = "#" + s;
	
	for(int i = 0; i < 26; i++){
		for(int j = 1; j <= n; j++){
			sum[i][j] = sum[i][j-1];
			if(s[j] == i+'a') sum[i][j]++;
		}
	}
	
	llint l, r;
	for(int q = 0; q < Q; q++){
		cin >> l >> r;
		
		if(l == r){
			cout << "Yes" << "\n";
			continue;
		}
		
		llint cnt = 0;
		for(int i = 0; i < 26; i++){
			if(sum[i][r] - sum[i][l-1]) cnt++;
		}
		if(cnt == 1) cout << "No" << "\n";
		else if(cnt >= 3) cout << "Yes" << "\n";
		else{
			if(s[l] == s[r]) cout << "No" << "\n";
			else cout << "Yes" << "\n";
		}
	}
	flush(cout);
	
	return 0;
}