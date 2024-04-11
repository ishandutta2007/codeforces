#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s ;
	double x,y,k,d;
	x = 0;
	y = 1;
	for(int i = 0 ; i < s.length();i++)
	{
		k = (x + y) /2;
		d = y - k ;
		if ( s[i] == 'l' )
			y = y - d;
		else
			x = x + d;
		if ( s[i] == 'r' ) 
			cout << i + 1 << endl;
	}
	
	x = 0;
	y = 1;
	for(int i = s.length() -1 ; i >=0;i--)
	{
		k = (x + y) /2;
		d = y - k ;
		if ( s[i] == 'l' )
			y = y - d;
		else
			x = x + d;
		if ( s[i] == 'l' ) 
			cout << i + 1 << endl;
	}
	
}