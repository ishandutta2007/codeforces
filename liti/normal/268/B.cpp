#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	long r = 0;
	for(int i = 0 ; i < n ; i++)
	{
		r += ( n  - i - 1 ) * (i+1);
	}
	cout << r+n << endl;
}