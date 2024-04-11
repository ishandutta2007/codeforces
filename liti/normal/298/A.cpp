#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int r=-1,t=-1;
	bool check = false;
	for(int i =0 ;i < n; i++) 
	{
		if ( s[i] == 'R' && check == false ) {

			r = i + 1;
			check = true;
		}
		if ( s[i] == 'L' ) 
		{
			t =  i  ;
			break;
		}
	}
	if ( r == -1 ) 
	{
		for( int i = n - 1 ; i >= 0 ; i-- ) 
		{
			if ( s[i] == 'L' )
			{	
				r = i + 1;
				break;
			}
		}
	}
	if ( t == -1 ) 
	{
		for(int i = n -1 ; i >= 0; i-- ) 
		{
			if ( s[i] == 'R' ) 
			{
				t = i + 2;
				break;
			}
		}
	}
	cout << r << ' ' << t << endl;
}