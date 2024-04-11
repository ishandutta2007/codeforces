#include <iostream>

using namespace std;

int x;

int main(void)
{
	cin >> x;
	for(int a = 2; a <= x; a++){
		for(int b = 2; b <= x; b++){
			if(a%b == 0 && a*b>x && a/b < x){
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}