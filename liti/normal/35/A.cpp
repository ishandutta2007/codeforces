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
#include <fstream>

#define cin fin
#define cout fout
using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

int main() 
{
	int x; 
	cin >> x; 
	for(int i = 0 ; i < 3 ; i++ ) 
	{
		int a,b;
		cin >> a >> b; 
		if ( a == x ) 
			x = b;
		else if ( b == x ) 
			x = a; 
	}
	cout << x << endl;
}