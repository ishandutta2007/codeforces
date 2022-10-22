#include <iostream>
#define llint long long

using namespace std;

llint T, s, i, e;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s >> i >> e;
		llint l = (i+e-s)/2+1;
		if(i+e-s < 0) l = 0;
		cout << max(0LL, e-l+1) << endl;
	}
	return 0;
}