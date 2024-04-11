#include <iostream>
#define llint long long

using namespace std;

llint T;
llint a, b, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b >> c;
		llint s = (a+b+c)/2, m = max(a, max(b, c));
		if(m <= s) cout << s << endl;
		else cout << (a+b+c)-m << endl;
	}
	return 0;
}