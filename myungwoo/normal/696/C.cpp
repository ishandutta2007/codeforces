#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

const int MOD = (int)1e9 + 7;
int K;

int _pow_(int a, lld p)
{
	int v = a, ret = 1;
	for (;p;p>>=1,v=(lld)v*v%MOD) if (p&1) ret = (lld)ret*v%MOD;
	return ret;
}

int main()
{
	scanf("%d", &K);
	int two = 2, m_one = MOD-1;
	for (int i=1;i<=K;i++){
		lld n; scanf("%lld", &n);
		two = _pow_(two, n);
		m_one = _pow_(m_one, n);
	}
	two = (lld)two * _pow_(2, MOD-2) % MOD;
	m_one = (lld)m_one * _pow_(MOD-1, MOD-2) % MOD;
	int p = (lld)(two-m_one + MOD) % MOD * _pow_(3, MOD-2) % MOD, q = two;
	printf("%d/%d\n", p, q);
}