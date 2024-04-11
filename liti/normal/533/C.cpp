/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2; 

	if( x1 <= x2 && y1 <= y2 ) 
		cout << "Polycarp" << endl;
	else if( x2 <= x1 && y2 <= y1 ) 
		cout << "Vasiliy" << endl;
	else { 
		int f = x1 + y1;
		int s = x2 + y2 - min( x2 , y2 );
		if( f <= s ) 
			cout << "Polycarp" << endl;
		else
			cout << "Vasiliy" << endl;
	}
}