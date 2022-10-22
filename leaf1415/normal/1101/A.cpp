#include <iostream>
#define llint long long

using namespace std;

int Q;

int main(void)
{
	cin >> Q;
	for(int q = 0; q < Q; q++){
		llint l, r, d;
		cin >> l >> r >> d;
		
		if(l > d) cout << d << endl;
		else{
			cout << r/d*d+d << endl;
		}
	}
	return 0;
}