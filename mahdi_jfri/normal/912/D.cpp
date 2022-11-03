#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ld long double

const int maxn = 1e5 + 20;

ll n , m , r;

set<pair<ll , ll> > st;

int L[maxn] , R[maxn] , x[maxn];

ll get(ll x , ll y)
{
	return (min(n - r + 1 , x) - max(1ll , (x - r + 1)) + 1) * (min(m - r + 1 , y) - max(1ll , (y - r + 1)) + 1);
}

void nxt(int i)
{
	if(x[i] == L[i] - 1)
		L[i]--;
	if(x[i] == R[i])
		R[i]++;
	if(R[i] - L[i] == m)
		x[i] = -1;
	else
	{
		if(L[i] - 1 >= 1)
			x[i] = L[i] - 1;
		else
			x[i] = R[i];
		if(L[i] - 1 >= 1 && get(i , x[i]) < get(i , L[i] - 1))
			x[i] = L[i] - 1;
		if(R[i] <= m && get(i , x[i]) < get(i , R[i]))
			x[i] = R[i];
	}
}

int main()
{
	int k;
	cin >> n >> m >> r >> k;
	for(int i = 1; i <= n; i++)
	{
		L[i] = R[i] = m - r + 1;
		st.insert({get(i , L[i]) , i});
		x[i] = L[i];
	}
	ll res = 0;
	for(int i = 0; i < k; i++)
	{
		auto it = st.end();
		it--;
		res += it -> first;
		int z = it -> second;
		st.erase(it);
		nxt(z);
		if(x[z] != -1)
			st.insert({get(z , x[z]) , z});
	}
	cout << fixed << setprecision(10) << ((ld)res / (ld)(n - r + 1) / (ld)(m - r + 1)) << endl;
}