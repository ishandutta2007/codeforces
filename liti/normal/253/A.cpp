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
#define cin fin
#define cout fout

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string s[2] = {"G","B"};

int main() 
{
	int n,m;
	cin >> n >> m;
   

	int x = 1; 	
	if ( m > n )
	   x = 0 ;
	
	int sum = m + n; 
	for(int i =  0 ; i < sum; i++ ) 
	{
		if ( m == 0 )
		{
			cout << s[1];
			continue;
		}
		if ( n == 0 ) 
		{
			cout << s[0];
			continue;
		}
		cout << s[x];
		if ( x == 1 ) 
			n--;
		else
			m--;
		x = ( x + 1 ) % 2; 
	}
	cout << endl;
}