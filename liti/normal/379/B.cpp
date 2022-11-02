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

const int maxN = 300 + 10;
int a[maxN];

int main() 
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++ )
		cin >> a[i];
	string s = "";
	string aa = "LRP";
	string b = "RLP";

	for(int i = 0 ; i < n ; i++ ) 
	{
		if ( i == 0 ) 
		{	if ( a[i] != 0 ) 
			{
				s += "P"; 
				for(int j = 1 ; j < a[i]; j++ ) 
					s += b;
			}
		}
		else
		{
			for(int j = 0 ; j < a[i] ; j++ ) 
				s += aa;
		}
		if ( i != n - 1 ) 
			s += "R";
	}
	cout << s << endl;
	
}