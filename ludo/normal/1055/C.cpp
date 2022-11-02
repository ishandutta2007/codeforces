#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return a; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll L1, R1, M1;
	ll L2, R2, M2;
	cin >> L1 >> R1 >> M1;
	cin >> L2 >> R2 >> M2;
	
	ll g = gcd(M1, M2);

	if (M1 > M2) {
		swap(L1, L2);
		swap(R1, R2);
		swap(M1, M2);
	}

	ll lol = L2 % M1 + (L1 - L2 % M1) / g * g; // remove remainder
	if (lol > L1) lol -= g;
	assert(lol <= L1);

	ll lor = lol + (R2 - L2);

	ll ret = 0;
	ret = max(ret, 1+min(lor+0, R1) - max(lol+0, L1));
	ret = max(ret, 1+min(lor+g, R1) - max(lol+g, L1));
	cout << ret << endl;
	return 0;
}