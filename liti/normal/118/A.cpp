#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <deque>

#define SZ(x) (( (int) x.size() ))

using namespace std;

int main() 
{
	string s; 
	cin >> s; 

	string r = "";

	for(int i = 0 ; i < SZ(s) ; i++ )
	{
		if ( s[i] <= 'Z' ) 
			s[i] += 'a' - 'A';
		if ( s[i] != 'a' && s[i] != 'o' && s[i] != 'u' &&
				s[i] != 'e' && s[i] != 'y' && s[i] != 'i' ) 
		{
			r += '.';
			r += s[i];
		}
	}

	cout << r << endl;
}