#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

LL n , k , sk , cnt , ans , pw;
vector<LL> v , w;

int main()
{
	LL i , j;
	cin >> n >> k;
	sk = sqrt(k);
	while (sk*sk < k) sk++;
	while (sk*sk > k) sk--;
	for (i = 2 ; i <= sk ; i++)
	{
		if (k%i == 0)
		{
			cnt = 0;
			while (k%i == 0)
			{
				k /= i;
				cnt++;
			}
			v.push_back(i);
			w.push_back(cnt);
		}
	}
	if (k > 1)
	{
		v.push_back(k);
		w.push_back(1);
	}
	ans = n;
	for (i = 0 ; i < v.size() ; i++)
	{
		cnt = 0;
		pw = 1;
		while (n/pw >= v[i])
		{
			pw *= v[i];
			cnt += n/pw;
		}
		ans = min(ans,cnt/w[i]);
	}
	cout << ans << "\n";
	return 0;
}