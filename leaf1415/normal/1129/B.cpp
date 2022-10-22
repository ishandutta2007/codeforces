#include <iostream>
#define llint long long

using namespace std;

llint k;
llint a[2005];

int main(void)
{
	cin >> k;
	
	llint x = (k+1999)/2000+2, y;
	if(x > 2004){
		for(;;x++){
			y = 2000*(x-2)-k;
			if(x >= 2005 && x < y) break;
		}
		cout << 2000 << endl;
		cout << y << " " << -(y+1) << " ";
		for(int i = 0; i < 1996; i++) cout << 0 << " ";
		cout << -1 << " " << x << endl;
	}
	else{
		llint x = (k+899)/900+2, y;
		for(;;x++){
			y = 900*(x-2)-k;
			if(x >= 905 && x < y) break;
		}
		cout << 900 << endl;
		cout << y << " " << -(y+1) << " ";
		for(int i = 0; i < 896; i++) cout << 0 << " ";
		cout << -1 << " " << x << endl;
	}
	
	return 0;
}