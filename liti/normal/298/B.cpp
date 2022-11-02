#include <iostream>
using namespace std;
int main()
{
	int t, sx, sy, ex, ey;
	cin >> t >> sx >> sy >> ex >> ey ;

	string s;
	cin >> s;

	int x = ex - sx;
	int y = ey - sy;

	int time = -1;
	int ds=0, de=0, dn = 0, dw= 0;

	for(int i = 0 ; i < t; i++ )
	{
		if ( s[i] == 'S' ) 
			ds ++;
		if ( s[i] == 'N' ) 
			dn ++;
		if ( s[i] == 'W' )
			dw ++;
		if ( s[i] == 'E' )
			de ++;
		bool c1 = false, c2 = false;
		if ( x >= 0 && x <= de )
			c1 = true;
		if ( x <= 0 && -x <= dw ) 
			c1 = true;
		if ( y >= 0 && y <= dn )
			c2 = true;
		if ( y <= 0 && -y <= ds ) 
			c2 = true;
		if ( c1 && c2 ) 
		{
			time = i + 1;
			break;
		}
	}
	cout << time << endl;
}