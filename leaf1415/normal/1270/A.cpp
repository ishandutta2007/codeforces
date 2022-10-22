#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, k1, k2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k1 >> k2;
		llint a; bool flag = false;
		for(int i = 1; i <= k1; i++) cin >> a;
		for(int i = 1; i <= k2; i++){
			cin >> a;
			if(a == n) flag = true;
		}
		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}