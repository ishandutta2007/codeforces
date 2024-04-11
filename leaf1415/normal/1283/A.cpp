#include <iostream>
#define llint long long

using namespace std;

llint T;
llint h, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> m;
		m += 60*h;
		cout << 60*24-m << "\n";
	}
	flush(cout);
	
	return 0;
}