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

int a[21] ; 

void addA(int i)
{
	a[i + 10]++;
}

long long getA(int i)
{
	return a[i+10];
}

int main() 
{
	int n;
	cin >> n; 

	for(int i =0 ; i < n ;i++ )
	{
		int x;
		cin >> x; 
		addA(x);
	}

	long long ans = ( getA(0)*(getA(0) - 1 ) ) / 2 ; 
	for(int i = 1 ; i < 11 ;i++ ) 
	{
		ans += getA(i)*getA(-i);
	}
	cout << ans << endl;
}