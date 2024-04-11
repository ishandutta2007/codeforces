#include <iostream>
#include <cstdlib>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cout << "? ";
	for(int i = 1; i <= k; i++) cout << i << " "; cout << endl;
	
	llint pos, val;
	cin >> pos >> val;
	
	cout << "? ";
	for(int i = 1; i <= k+1; i++){
		if(i != pos) cout << i << " ";
	}
	cout << endl;
	
	llint pos2, val2;
	cin >> pos2 >> val2;
	
	llint ans = 0, p, v;
	for(int i = 1; i <= k+1; i++){
		if(i == pos || i == pos2) continue;
		cout << "? ";
		for(int j = 1; j <= k+1; j++){
			if(j != i) cout << j << " ";
		}
		cout << endl;
		cin >> p >> v;
		if(val < val2){
			if(v == val2) ans++;
		}
		else{
			if(v != val2) ans++;
		}
	}
	cout << "! " << ans+1 << endl;
	
	return 0;
}