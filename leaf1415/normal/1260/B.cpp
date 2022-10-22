#include <iostream>
#define llint long long

using namespace std;

llint T;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	llint a, b;
	for(int t = 0; t < T; t++){
		cin >> a >> b;
		if((a+b)%3){
			cout << "NO" << endl;
			continue;
		}
		llint d = (a+b)/3;
		a -= d, b -= d;
		if(a >= 0 && b >= 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}