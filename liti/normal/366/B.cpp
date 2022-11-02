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

const int maxN = 100*100*10 + 10;

int a[maxN]; 

int main() 
{
	int n,k;
	cin >> n >> k;

	for(int i = 0 ; i < n ; i++ ) 
	{
		int num;
		cin >> num;
		a[ i % k ] += num;
	}

	int best = a[0], bi = 0;
	for(int i = 0 ; i < k ; i++ )
		if ( best > a[i] ) {
			best = a[i];
			bi = i; 
		}
	cout << bi + 1 << endl;
}