#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
	string s;
	cin >> s;
	long long hCounter = 0, result = 0;
	if ( s.size() < 5 ) 
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0 ; i < s.size() - 4; i++ ) 
	{
		if ( s.substr(i,5) == "heavy" )  
			hCounter++;
		if ( s.substr(i,5) == "metal" ) 
			result+= hCounter;
	}
	cout << result << endl;
			
}