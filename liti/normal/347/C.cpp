#include <iostream> 
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

int gcd(int a,int b)
{
	if ( a > b ) 
		swap(a,b);
	if ( a == 0 ) 
		return b;
	return gcd( b % a , a ) ; 

}
int main()
{
	int n;
	cin >> n; 
	int max = 0 ; 
	int gc;
	cin >> gc;
	max = gc;
	for(int i = 1; i < n ;i++ )
	{
		int num;
		cin >> num;
		gc = gcd( gc, num ) ; 
		if ( num > max ) 
			max = num ; 
	}

	cout << ( ( max / gc - n ) % 2 == 0 ? "Bob" : "Alice" ) << endl;
}