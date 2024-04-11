#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n;
llint a;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		llint x = ((7-a)%14+14)%14;
		if(a < 15){
			cout << "NO" << endl;
			continue;
		}
		if(x >= 1 && x <= 6) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}