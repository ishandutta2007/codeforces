#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;


bool solve()
{
	int n,count(0);

	cin >> n;

	if((n <= 10)||(n > 21)){cout << count;return true;}

	if((n < 20)||(n==21))cout << "4";
	if(n == 20) cout << "15";


	return true;
}

int main(int argc,char** argv)
{
	setlocale(LC_ALL,"Russian");

	solve();

	return 0;
}