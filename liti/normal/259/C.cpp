#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	string s;
	cin >> s;
	bool check = true;
	string result = "";
	for(unsigned int i = 0 ; i < s.length() ; i++)
	{
		if ( s[i] == '0' && check )
			check = false;
		else{
			if ( check && i == s.length() -1 )
				check = false;
			else
				result+= s[i];
		}
	}
	cout << result << endl;
	return 0;
}