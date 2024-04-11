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

int a[101] ;

int main() 
{
	int n; 
	cin >> n; 
	for(int i = 0 ; i < n ;i++ )
	{
		int x;
		cin >> x; 
		x--;
		a[x] = i;
	}
	for(int i = 0 ; i < n ;i++ )
		cout << a[i] + 1<< ' ' ; 
	cout << endl;
}