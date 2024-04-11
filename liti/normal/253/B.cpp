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
#define cout fout
#define cin fin

using namespace std;

ifstream fin( "input.txt" );
ofstream fout( "output.txt" );

const int maxN = 100*100*10 + 100; 
int a[maxN];

int main()
{
	int n; 
	cin >> n; 

	for(int i = 0 ;i < n ;i++ )
		cin >> a[i]; 
	sort( a, a + n ); 

	int index = 0; 

	int ans = n ; 

	for(int i = 0 ; i < n ; i++ )
	{
		int x = a[i] / 2  + ( a[i] % 2 ) ;
	 	while ( x > a[index] ) 
	 	  	index++;	 

		int count = i - index + 1; 
//		cout << i << ' ' << index << ' ' <<n -  count << endl;
		if (  n - count < ans ) 
			ans = n -  count; 
	}
	
	cout << ans << endl;
}