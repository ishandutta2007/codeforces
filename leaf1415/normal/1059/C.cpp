#include <iostream>

using namespace std;

int n;

void calc(int k, int n)
{
	if(n == 1) cout << k << " ";
	if(n == 2) cout << k << " " << k*2 << " ";
	if(n == 3) cout << k << " " << k << " " << k*3 << endl;
	if(n >= 4){
		int e = n/2;
		for(int i = 1; i <= n-e; i++) cout << k << " ";
		calc(2*k, e);
	}
	
}

int main(void)
{
	cin >> n;
	calc(1, n);
	cout << endl;
	return 0;
}