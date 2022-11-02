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

string s[3] = {"chest", "biceps" , "back" };

int a[3];

int main() 
{
	int n; 
	cin >> n; 
	for(int i = 0 ; i < n ; i++ )
	{
		int x ; 
		cin >> x; 
		a[i%3] += x;
	}


	int bestId = 0, best = a[0];
	for(int i = 1; i < 3 ; i++  )
	{
		if ( best < a[i] )
		{
			best = a[i];
			bestId = i;
		}
	}
	cout << s[bestId] << endl;
}