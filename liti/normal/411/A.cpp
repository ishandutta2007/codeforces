#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

int main()
{
	string pass;
	cin >> pass;

	bool c1 = ( SZ(pass) >= 5 ) ; 
	bool c2 = false;
	for(int i = 0 ; i < SZ( pass ) ; i++ )
		if( pass[i] >= 'a' && pass[i] <= 'z' ) 
			c2 = true;
	bool c3 = false;
	for(int i = 0 ; i < SZ( pass ) ; i++ )
		if( pass[i] >= 'A' && pass[i] <= 'Z' ) 
			c3 = true;
	bool c4 = false;
	for(int i = 0 ; i < SZ( pass ) ; i++ )
		if( pass[i] >= '0' && pass[i] <= '9' ) 
			c4 = true;

	cout << ( c1 && c2 && c3 && c4 ? "Correct" : "Too weak" ) << endl;
}