#include <iostream>

using namespace std;

int x, y;

int main(void)
{
	cin >> x >> y;
	if(y == 1 && x != 0){
	    cout << "No" << endl;
	    return 0;
	}
	if(y > 0 && x >= y-1 && (x-y) % 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}