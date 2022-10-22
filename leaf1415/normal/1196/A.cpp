#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint Q;
llint a[3];

int main(void)
{
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		
		llint hf = (a[0]+a[1]+a[2])/2;
		cout << min(hf, a[0]+a[2]) << endl;
	}
	return 0;
}