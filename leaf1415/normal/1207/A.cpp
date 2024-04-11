#include <iostream>
#define llint long long

using namespace std;

llint T;
llint b, p, f;
llint h, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> b >> p >> f >> h >> c;
		
		llint ans = 0;
		for(int i = 0; i <= p; i++){
			for(int j = 0; j <= f; j++){
				if((i+j)*2 > b) continue;
				ans = max(ans, i*h+j*c);
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}