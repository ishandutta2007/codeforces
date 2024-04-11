#include <iostream>
#define llint long long

using namespace std;

llint T;
llint r, g, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> r >> g >> b;
		llint sum = r + g + b, ok = (sum+1)/2;
		if(r <= ok && g <= ok && b <= ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}