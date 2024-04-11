#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long a , b , i , s;

int main ()
{
	s = 1;
	cin >> a >> b;
	for (i = 1 ; i <= min(a,b) ; i++)
		s *= i;
	cout << s << "\n";	
	//system("PAUSE");
	return 0;
}