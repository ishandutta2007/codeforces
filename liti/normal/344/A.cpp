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
	int n; 
	cin >> n ; 

	int g = 1 ; 
	int c = 2 ; 
	for(int i =0 ; i < n ; i++ )
	{
		string a; 
		cin >> a;
		int s = 0;
		if ( a == "10" ) 
			s = 1;
		if ( c != 2 && s != c ) 
			g++; 
		c =  s ; 
	}
	cout << g << endl;
}