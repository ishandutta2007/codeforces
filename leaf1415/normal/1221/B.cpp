#include <iostream>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if((i+j)%2) cout << "B";
			else cout << "W";
		}
		cout << endl;
	}
	
	return 0;
}