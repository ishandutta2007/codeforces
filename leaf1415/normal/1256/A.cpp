#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint a, b, n, S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> a >> b >> n >> S;
		if(b >= n){
			if(S <= a*n+b) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
		else{
			if(S <= a*n+b && S%n <= b) cout << "YES" << "\n";
			else cout <<"NO" << "\n";
		}
	}
	flush(cout);
	
	return 0;
}