#include <iostream>
using namespace std;

string jam( string s1, string s2 ) 
{
	string result = "0";
	bool d = false;
	for(int i = s1.length() - 1 ; i >= 0 ; i-- ) 
	{
		result[ 0 ] += ( s1[i] + s2[i] - 96 ) + d ;
		if ( result [ 0 ]  - 48 > 9 ) 
			d = true;
		else
			d = false;
		result[0 ] = ( ( result[ 0 ] - 48 ) % 10 ) + 48;
		result = '0' + result;
	}
	if ( d == true ) 
		result[0] = '1';
	else
		result = result.substr( 1, result.size() - 1 );
	return result;
}
void zarb( string& s, int adad ) 
{
	if ( adad == 10 ) 
	{
		s += '0';
		return;
	}
	string tmp = s;
	for(int i =  0 ; i < adad-1 ; i++ )
	{
		if ( s.size() > tmp.size() )
			tmp = '0' + tmp;
		s =jam( tmp, s ) ;
	}
}
int main()
{
	string s;
	cin >> s;
	string result = "1";
	bool ch[10];
	for(int i = 0; i < 10; i++ ) 
		ch[i] = false;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		if ( s[i] <= '9' && s[i] >= '0' ) 
			continue;
		if ( s[i] == '?' ) 
			zarb(result , 10);
		else
			ch[ s[i] - 'A' ] = true;
	}
	int adad = 10;
	string r = "1";
	for(int i = 0 ; i < 10 ; i++ ) 
	{
		if ( ch[i] ) 
		{
			if ( adad == 10 ) 
				zarb( result, adad);
			else
				zarb(r, adad);
			adad--;
		}
	}

	if ( ( s[0] >= 'A' && s[0] <= 'J' ) || s[0] == '?'  ) 
	{ 
		result = result.substr( 0, result.size() - 1 );
		zarb(r, 9 );
	}

	result = r + result.substr( 1, result.size() - 1 ) ;
	cout << result << endl;
}