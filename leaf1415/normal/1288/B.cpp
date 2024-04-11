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
	for(int t = 1; t <= T; t++){
		cin >> a >> b;
		llint cnt = 0;
		for(llint x = b+1; x; x/=10) cnt++;
		cnt = max(cnt, 1LL);
		cout << a * (cnt-1) << endl;
	}
	
	return 0;
}