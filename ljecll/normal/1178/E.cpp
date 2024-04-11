#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000007
#define LLINF 2696969696969696969ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

string s;
int l, r;
string ans;
string lt;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	//among any 4 characters you have to have two equals
	r = SZ(s) - 1; l = 0;
	FOR(i, 0, SZ(s) / 4)
	{
		map<char, int> mpch;
		mpch[s[l]]++;
		mpch[s[l + 1]]++;
		mpch[s[r]]++;
		mpch[s[r - 1]]++;
		for (auto it : mpch)
		{
			if (it.se >= 2)
			{
				lt += it.fi;
				break;
			}
		}
		l += 2;
		r -= 2;
	}
	ans = lt;
	if (l <= r)
	{
		ans += s[l];
	}
	reverse(ALL(lt));
	ans += lt;
	cout << ans << '\n';
	return 0;
}