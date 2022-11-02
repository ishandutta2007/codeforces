#include <iostream> 
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() 
{
	string s; 
	cin >> s ; 


	if ( s.size() % 2 == 1 ) 
	{
		cout << "No" << endl;
		return 0; 
	}
	for(int i = 0 ; i < (int)s.size() - 1  ; i++ )
	{
	//	cout << s << endl;
		string a = s.substr(i,2); 
	//	cout << "D" << endl;
		if (  a == "++" || a == "--"  ) 
		{
			s = s.substr( 0 , i ) + s.substr( i + 2 , s.size() - ( i + 2 ) + 1 ) ; 
			i = max( -1, i - 2 );
		}
	//	cout << i << endl;
	//	cout << "B" << endl;
	}
	if ( s.size() == 0 ) 
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}