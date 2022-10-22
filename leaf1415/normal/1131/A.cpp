#include <iostream>
#define llint long long

using namespace std;

llint w1, h1, w2, h2;

int main(void)
{
	cin >> w1 >> h1 >> w2 >> h2;
	
	if(w1 == w2){
		cout << 2*(w1+h1+h2) + 4 << endl;
		return 0;
	}
	else{
		cout << 2*(w1+h1)+4-w2 + 2*(w2+h2-1)+4 - (w2+2) << endl;
		return 0;
	}
	
	return 0;
}