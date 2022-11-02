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

const int maxN = 100 + 10; 
int a[maxN]; 

int main() 
{
	int n, k;
	cin >> n >> k; 

	for(int i = 0 ; i < n ; i++ ) 
	{
		int num; 
		cin >> num ; 
		a[i] = num * ( n - i ) ; 
	}
	sort( a, a + n ) ; 

	int sum = 0 ; 
	int i ; 
	for(i = 0 ; i < n && sum + a[i] <= k ; i++ )
		sum+= a[i];
//	cout << sum << endl;
	cout << i << endl; 
}