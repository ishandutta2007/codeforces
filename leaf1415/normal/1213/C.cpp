#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> m;
		
		llint sum = 0;
		for(int i = 1; i <= 10; i++) sum += i*m%10;
		
		llint ans = (n/m)/10*sum;
		for(int i = 1; i <= (n/m)%10; i++) ans += i*m%10;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}