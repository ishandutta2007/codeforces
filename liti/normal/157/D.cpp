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

const int maxN = 100*100*10 + 123;

int a[2*maxN], b[maxN];
int check[2*maxN];
int main()
{
	int n,m;
	cin >> n >> m;

	int pC= 0 , mC = 0 ; 
	for(int i = 0 ; i < n ;i++ )
	{
		cin >> b[i];
		a[maxN + b[i] ] ++;
		if ( b[i] < 0 ) 
			mC++;
		else
			pC++;
	}

	int counter = 0 ;
	for(int i =1 ; i <= n ; i++ )
	{
		int y = mC + a[maxN + i]  - a[maxN - i]; 
		int x = pC -  a[maxN + i]  + a[maxN - i];
		
		if ( y == m ) 
		{
			check[maxN+i] = 1; 
			check[maxN-i] =  1; 
			counter++;
		}
	}

	for(int i = 0 ; i < n ; i++ )
	{
		int num = b[i];
		if ( check[ maxN + num ] == 0 ) 
		{
			if ( num < 0 ) 
				cout << "Truth" << endl;
			else
				cout << "Lie" << endl;
			continue;
		}
		if ( counter > 1 ) 
			cout << "Not defined" << endl;
		else if ( num < 0 ) 
			cout << "Lie" << endl;
		else
			cout << "Truth" << endl;
	}
}