#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

LL NOD(LL x, LL y)
{
	if(x != 0)
		NOD(y%x,x);
	else
		return y;
}
LL NOK(LL x, LL y)
{
	return y*(x/NOD(x,y));
}


bool solve()
{
	int x,y,a,b;
	int count1(0),count2(0);

	cin >> x >> y >> a >> b;
	count1 = a;count2 = b;

	for(int i(a);i%NOK(x,y) != 0;i++)
		count1++;

	for(int i(b);i%NOK(x,y) != 0;i--)
		count2--;

	cout << (count2-count1)/NOK(x,y) + 1;


	return true;
}

int main(int argc,char** argv)
{
	solve();

	return 0;
}