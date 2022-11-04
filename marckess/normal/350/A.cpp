
#include <iostream>

using namespace std;

int main(){
	int n, minc, maxc, minw, m, x;
	cin >> n >> m >> minc;
	maxc = minc;

	while ( --n ){
		cin >> x;
		if ( x < minc )
			minc = x;
		if (x > maxc)
			maxc = x;
	} 

	cin >> minw;
	while (--m){
		cin >> x;
		if (x < minw)
			minw = x;
	}

	if ( minc * 2 <= maxc && maxc < minw )
		cout << maxc;
	else if ( minc * 2 < minw  && minc * 2 >= maxc )
		cout << minc * 2;
	else
		cout << -1;

	return 0;
}