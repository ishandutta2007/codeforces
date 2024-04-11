#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<int> splim;
	vector<int> ov;
	ov.push_back(0);
	splim.push_back(1000);
	int sp = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int t, x;
		cin >> t;
		if(t == 1) cin >> sp;
		if(t == 2){
			while(ov[ov.size()-1]){
				ov.pop_back();
				ans++;
			}
		}
		if(t == 3){
			int x;
			cin >> x;
			splim.push_back(x);
		}
		if(t == 4){
			ov.push_back(0);
		}
		if(t == 5){
			splim.push_back(10000);
		}
		if(t == 6){
			ov.push_back(1);
		}
		while(splim[splim.size()-1] < sp){
			ans++;
			splim.pop_back();
		}
	}
	cout << ans << endl;
}