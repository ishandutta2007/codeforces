#include <iostream>
#define llint long long 

using namespace std;

llint l, r;

int main(void)
{
	cin >> l >> r;
	
	cout << "YES" << endl;
	for(llint i = l; i <= r; i+=2){
		cout << i << " " << i+1 << endl;
	}
	return 0;
}