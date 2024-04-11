#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	if ( s[0] != '-' ) 
		cout << s << endl;
	else
	{
		int index = s.size() - 1;
		if ( s.size() > 2 && s[s.size() - 1] < s[s.size() - 2 ] ) 
		{
			index--;
		}
		string result = "";
		for(int i =0 ; i < s.size() ; i++ ) 
			if ( i != index )
				result += s[i];
	   if ( result == "-0" ) 
		   cout << 0 << endl;
	   else
		   cout << result << endl;
	}	   
}