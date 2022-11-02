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

const int maxN = 1000 + 123;

pair<int, int> a[maxN];

int main() 
{

	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++ )
		cin >> a[i].second >> a[i].first ; 
	sort( a, a + n ) ; 
	reverse( a, a + n ) ; 

	int counter = 1 ;
   int score = 0 ; 	
	for(int i = 0 ; i < n ; i++ )
	{
		if ( counter == 0 ) 
			break;
		counter--;
		counter+= a[i].first;
		score += a[i].second ; 
	}
	cout << score << endl;
}