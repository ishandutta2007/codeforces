#include <iostream>
#define llint long long

using namespace std;

int n;

int main(void)
{
	cin >> n;
	if(n%2){
		cout << 0 << endl;
		return 0;
	}
	cout << (1LL<<(n/2)) << endl;
	return 0;
}