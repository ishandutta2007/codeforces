#include <iostream>
#define llint long long

using namespace std;

llint T;
llint a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b;
		if(a == b) cout << 0 << "\n";
		else if(a < b){
			if((b-a)%2) cout << 1 << "\n";
			else cout << 2 << "\n";
		}
		else{
			if((b-a)%2) cout << 2 << "\n";
			else cout << 1 << "\n";
		}
	}
	flush(cout);
	
	return 0;
}