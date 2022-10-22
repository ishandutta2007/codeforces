#include <iostream>

using namespace std;

int n, m;

int main(void)
{
	cin >> n >> m;
	
	if(n >= 30){
		cout << m << endl;
		return 0;
	}
	
	cout << (m & ((1<<n)-1)) << endl;
	return 0;
}