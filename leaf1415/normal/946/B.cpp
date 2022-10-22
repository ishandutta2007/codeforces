#include <iostream>
#define llint long long

using namespace std;

llint a, b;

int main(void)
{
	cin >> a >> b;
	
	while(a && b){
		if(a >= 2*b) a %= 2*b;
		else if(b >= 2*a) b %= 2*a;
		else break;
	}
	
	cout << a << " " << b << endl;
	return 0;
}