#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint c, m, x;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> c >> m >> x;
		llint ans = min((c+m+x)/3, min(c, m));
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}