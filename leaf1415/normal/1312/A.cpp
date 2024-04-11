#include <iostream>
#define llint long long
#define rep(i, s, t) for(llint (i) = (s); (i) <= (t); (i)++)

using namespace std;

llint T;
llint n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	rep(t, 1, T){
		cin >> n >> m;
		if(n % m == 0) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}