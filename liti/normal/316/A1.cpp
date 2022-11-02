#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	long long result = 1;
	bool ch[10];
	for(int i = 0; i < 10; i++ ) 
		ch[i] = false;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		if ( s[i] <= '9' && s[i] >= '0' ) 
			continue;
		if ( s[i] == '?' ) 
			result *= 10;
		else
			ch[ s[i] - 'A' ] = true;
	}
	int adad = 10;
	for(int i = 0 ; i < 10 ; i++ ) 
	{
		if ( ch[i] ) 
		{
			result *= adad;
			adad--;
		}
	}

	if ( ( s[0] >= 'A' && s[0] <= 'J' ) || s[0] == '?'  ) 
		result = (result / 10)*9;
	cout << result << endl;
}