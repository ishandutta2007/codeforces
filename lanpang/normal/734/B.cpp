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

int a , b , c , d , t1 , t2;

int main ()
{
	cin >> a >> b >> c >> d;
	t1 = min(a,min(c,d));
	a -= t1;
	t2 = min(a,b);
	cout << t1*256+t2*32 << "\n";
	//system("PAUSE");
	return 0;
}