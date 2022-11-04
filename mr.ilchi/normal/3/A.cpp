/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

char sx, sy, ex, ey;

int main (){
	cin >> sx >> sy >> ex >> ey;
	cout << max (labs (sx-ex), labs (sy-ey)) << endl;
	while (sx!= ex || sy!= ey){
		if (sx < ex){
			cout << 'R';
			sx ++;
		}
		if (sx > ex){
			cout << "L";
			sx --;
		}
		if (sy < ey){
			cout << "U";
			sy ++;
		}
		if (sy > ey){
			cout << "D";
			sy --;
		}
		cout << endl;
	}	
	return 0;
}