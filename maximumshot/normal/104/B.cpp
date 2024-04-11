#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;


bool solve()
{
	LL sum(0),n,a;

	cin >> n;

	for(int i(0);i < n;i++)
	{
		cin >> a;

		sum += i*(a-1)+a;
	}

	cout << sum;

	return true;
}

int main(int argc,char** argv)
{
	setlocale(LC_ALL,"Russian");

	solve();

	return 0;
}