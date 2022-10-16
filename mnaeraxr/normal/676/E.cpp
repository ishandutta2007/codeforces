#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<string> coef(n+1);
	bool ok = false;
	
	int t = 0;
	
	
	for (int i = 0; i <= n; ++i){
		cin >> coef[i];		
		if (coef[i] == "?") ok = true;
		else t ^= 1;
	}
	
	if (k == 0){
		if (coef[0] == "?")
			cout << (t == 1 ? "Yes" : "No") << endl;
		else
			cout << (coef[0] == "0" ? "Yes" : "No") << endl;
		
		exit(0);
	}
	
	if (ok){
		cout << (n % 2 ? "Yes" : "No") << endl;
	}
	else{
		int r = -atoi(coef[0].c_str());
				
		for (int i = 1; i <= n; ++i){
			if (r % k) break;
			r = r / k - atoi(coef[i].c_str());
		}
		
		cout << (r == 0 ? "Yes" : "No") << endl;
	}
	
	return 0;
}