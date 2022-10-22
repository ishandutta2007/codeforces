#include <iostream>
#define llint long long

using namespace std;

llint T;
llint a, b, c, n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> a >> b >> c >> n;
		if((a+b+c+n)%3){
			cout << "NO" << "\n";
			continue;
		}
		llint m = max(a, max(b, c));
		llint need = m-a + m-b + m-c;
		if(need <= n) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}