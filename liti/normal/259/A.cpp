#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	for(int i = 0 ; i < 8 ; ++i )
	{
		
		int c=1;
		string n;
		cin >> n;
		if ( n[0] == 'B' )
			c = 0;
		
		for(int j = 0 ; j < 8 ; j++){
			if ( n[j] == 'B' )
				c++;
			if ( n[j] == 'W' )
				c--;
			if ( c > 1 || c < 0 ){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}