#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		if(n % 2){
			cout << 7;
			n -= 3;
		}
		for(int i = 0; i < n/2; i++) cout << 1;
		cout << endl;
	}
	
	return 0;
}