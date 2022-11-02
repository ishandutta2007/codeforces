#include <iostream>
using namespace std;

int main() 
{
	string s; 
	cin >> s; 

	if ( s[0] != '1' ) 
	{
		cout << "NO" << endl;
		return 0; 
	}

	for(int i = 1 ; i < s.size() ; i++ ) 
	{
		if ( s[i] != '4' && s[i] != '1' ) 
		{
			cout << "NO" << endl;
			return 0;
		}
		if ( s[i] == '4' && !( ( s[i-1] == '1' ) || ( s[i-1] == '4' && i >= 2 && s[i-2] == '1') ))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}