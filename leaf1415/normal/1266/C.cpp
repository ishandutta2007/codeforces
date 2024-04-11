#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint r, c;
llint ans[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	if(c == 1){
		if(r == 1){
			cout << 0 << endl;
			return 0;
		}
		for(int i = 1; i <= r; i++){
			cout << i+1 << endl;
		}
		return 0;
	}
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cout << i*(j+r) << " ";
		}
		cout << endl;
	}
	
	return 0;
}