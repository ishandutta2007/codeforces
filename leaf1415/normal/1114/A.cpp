#include <iostream>

using namespace std;

int x, y, z;
int a, b, c;

int main(void)
{
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	
	if(a < x){
		cout << "NO" << endl;
		return 0;
	}
	b += a-x;
	
	if(b < y){
		cout << "NO" << endl;
		return 0;
	}
	c += b-y;
	
	if(c < z){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	return 0;
}