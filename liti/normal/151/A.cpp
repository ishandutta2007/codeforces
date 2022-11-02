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


int main()
{
	int n,k,l,c,d,p,nl,np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np ;

	int x = k * l ; 
	int y = c * d; 
	int z = p/np;
	int q= x / nl;

	cout << min( min( y, z ) , q ) / n << endl;
}