#include <iostream>

using namespace std;

int main() {
	int t, sx, sy, ex, ey, dx, dy, r;
	char w;
	cin >> t >> sx >> sy >> ex >> ey;
	dx = ex-sx;
	dy = ey-sy;
	r=0;
	while((cin>>w) && (dx!=0 || dy!=0)) {
		switch(w) {
			case 'E':
				if(dx>0)
					dx--;
				break;
			case 'S':
				if(dy<0)
					dy++;
				break;
			case 'W':
				if(dx<0)
					dx++;
				break;
			case 'N':
				if(dy>0)
					dy--;
				break;
		}
		++r;
	}
	if((dx!=0)||(dy!=0))
		r = -1;
	cout << r << endl;
	return 0;
}