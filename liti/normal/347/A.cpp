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

int a[100];

int main()
{
	int n; 
	cin >> n ; 
	for(int i = 0 ; i < n ; i++ )
		cin >> a[i];
	sort( a, a + n );
	int c = n-1;
	cout << a[n-1] << ' ' ; 
	for(int i = 1 ; i < n - 1 ;i++ )
		cout << a[i] << ' ';
	cout << a[0] << endl;
}