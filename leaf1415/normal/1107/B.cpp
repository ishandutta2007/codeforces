#include <iostream>
#define llint long long 

using namespace std;

llint n;
llint k, x;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> k >> x;
		cout << 9*(k-1)+x << endl;
	}
	return 0;
}