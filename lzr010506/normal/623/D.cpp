#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
const int N = 107;
const double eps = 1e-9;
int p[N];
long double val[N];
int cnt[N];
set<pair<long double, int> > S;
int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	FOR(i,0,n)
	{
		cin >> p[i];
		val[i] = log(1.0 - 0.01 * p[i]);
		cnt[i] = 1;
		S.insert(MP(-(1 - exp(val[i] / cnt[i] * (cnt[i] + 1)))/(1 - exp(val[i])) , i));
	}
	long double res = 0;
	long double P = 1;
	FOR(i,0,n)
	{
		P *= (1 - exp(val[i]));
	}
	res += P * n;
	FOR(it,0,1000000)
	{
		int v = S.begin()->second;
		long double prev = P;
		S.erase(S.begin());
		P /= 1 - exp(val[v]);
		val[v] /= cnt[v];
		++cnt[v];
		val[v] *= cnt[v];
		P *= 1 - exp(val[v]);
		res += (P - prev) * (n + it + 1);
		S.insert(MP(-(1 - exp(val[v] / cnt[v] * (cnt[v] + 1)))/(1 - exp(val[v])) , v));
	}
	printf("%.10f\n" , (double)res);

	return 0;
}