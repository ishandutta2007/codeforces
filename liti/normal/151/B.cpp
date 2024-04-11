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

#define SZ(x) (( (int) x.size() ))

using namespace std;

vector<string> a , b , c ; 
int ind[6] = {0,1,3,4,6,7};
bool isT( string s ) 
{
	char t = s[0];
	for(int i = 0  ; i < 6 ; i++ )
		if ( s[ ind[i] ] != t ) 
			return false;
	return true;
}
bool isP( string s ) 
{
	char t = s[0];
	for(int i = 1 ; i < 6 ; i++ ) 
		if ( s[ ind[i] ] >= t ) 
			return false;
		else
			t = s[ ind[i] ] ; 
	return true;
}

int main()
{
	int n;
	cin >> n;

	int ma = 0  , mb = 0 ,  mc = 0 ; 

	for(int i = 0 ; i < n ; i++ ) 
	{
		string name;
		int m;
		cin >>  m >> name ; 

		int ta = 0 , tb = 0 , tc = 0 ; 
		for(int j = 0 ; j < m ; j++ )
		{
			string tmp;
			cin >> tmp;
			if ( isT( tmp ) ) 
				ta++;
			else if ( isP( tmp ) ) 
				tb++;
			else
				tc++;
		}
		if ( ta > ma ) 
		{
			ma = ta;
			a.clear();
		}
		if ( tb > mb ) 
		{
			mb = tb;
			b.clear() ; 
		}
		if ( tc > mc ) 
		{
			mc = tc ; 
			c.clear();
		}

		if ( ta >= ma ) 
			a.push_back(name);
		if ( tb >= mb ) 
			b.push_back(name);
		if ( tc >= mc ) 
			c.push_back(name);
	}

	cout << "If you want to call a taxi, you should call: " ; 
	for(int i = 0 ; i < SZ( a ) ; i++ ) 
		cout << ( i == 0 ? "" : ", " ) << a[i] ;
	cout << "." << endl << "If you want to order a pizza, you should call: ";
	for(int i = 0 ; i < SZ( b ) ; i++ )
		cout << (i== 0 ? "" : ", " ) << b[i];
	cout << "." << endl << "If you want to go to a cafe with a wonderful girl, you should call: " ;
	for(int i = 0 ; i < SZ( c ) ; i++ ) 
		cout << ( i == 0 ? "" : ", " ) << c[i];
	cout << "." << endl;
}