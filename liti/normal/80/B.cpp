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
	string s;
	cin >> s;

	long long h = (s[0]- '0' )*10 + s[1] -'0';
	long long m =  (s[3]- '0' )*10 + s[4] -'0';
	cerr << h << ' ' << m << endl;

	h %= 12;

	long double angle = h*30.0;

	angle += m/2.0;	
	cout << fixed << setprecision(3) << angle << ' ' << m*6.0 << endl;
}