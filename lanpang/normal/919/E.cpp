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

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL a , b , p , x , pp , ans;

LL qp(LL i , LL j)
{
	if (j == 0) return 1;
	LL ret = qp(i,j/2);
	if (j%2) return ret*ret%p*i%p;
	else return ret*ret%p;
}

int main ()
{
	LL i , j , k;
	cin >> a >> b >> p >> x;
	pp = p*(p-1);
	for (i = 1 ; i < p ; i++)
	{
		j = qp(a,i);
		j = b*qp(j,p-2)%p;
		k = ((p*i)+((p-1)*(p-1)%pp*j))%pp;
		ans += x/pp;
		if (x%pp >= k) ans++;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}