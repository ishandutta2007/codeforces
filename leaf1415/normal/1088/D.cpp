#include <iostream>

using namespace std;

int main(void)
{
	int c = 0, d = 0;
	bool big;
	int res;
	
	cout << "? " << 0 << " " << 0 << endl;
	cin >> res;
	big = (res >= 0);
	
	for(int i = 29; i >= 0; i--){
		if(big){
			cout << "? " << (c^(1<<i)) << " " << d << endl;
			cin >> res;
			if(res == -1){
				c ^= 1<<i;
				big = false;
				
				cout << "? " << c << " " << (d^(1<<i)) << endl;
				cin >> res;
				if(res >= 0){
					d ^= 1<<i;
					big = true;
				}
			}
			else{
				cout << "? " << c << " " << (d^(1<<i)) << endl;
				cin >> res;
				if(res >= 0) c ^= 1<<i;
			}
		}
		else{
			cout << "? " << c << " " << (d^(1<<i)) << endl;
			cin >> res;
			if(res >= 0){
				d ^= 1<<i;
				big = true;
				
				cout << "? " << (c^(1<<i)) << " " << d << endl;
				cin >> res;
				if(res == -1){
					c ^= 1<<i;
					big = false;
				}
			}
			else{
				cout << "? " << (c^(1<<i)) << " " << d << endl;
				cin >> res;
				if(res == -1) d ^= 1<<i;
			}
		}
	}
	cout << "! " << c << " " << d << endl;
	
	return 0;
}