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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int A, B, C, D, N;
vi ans;

bool work()
{
	if (A < 0 || B < 0 || C < 0 || D < 0) return false;
	int freq[4];
	freq[0] = A; freq[1] = B; freq[2] = C; freq[3] = D;
	FOR(i, 0, N - 1)
	{
		int x = ans.back();
		if (x == 0)
		{
			if (!freq[1])
			{
				return false;
			}
			freq[1]--;
			ans.PB(1);
		}
		else if (x == 3)
		{
			if (!freq[2])
			{
				return false;
			}
			freq[2]--;
			ans.PB(2);
		}
		else if (x == 1)
		{
			if (!freq[0])
			{
				if (!freq[2]) return false;
				freq[2]--;
				ans.PB(2);
			}
			else
			{
				freq[0]--;
				ans.PB(0);
			}
		}
		else if (x == 2)
		{
			if (!freq[3])
			{
				if (!freq[1]) return false;
				freq[1]--;
				ans.PB(1);
			}
			else
			{
				freq[3]--;
				ans.PB(3);
			}
		}
	}
	return true;
}
void printans()
{
	cout << "YES\n";
	FOR(i, 0, SZ(ans))
	{
		cout << ans[i] << " \n"[i == SZ(ans) - 1];
	}
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> A >> B >> C >> D;
	N = A + B + C + D;
	if (abs(A + C - B - D) > 1)
	{
		cout << "NO\n";
		return 0;
	}
	if (D - C > 1 || A - B > 1)
	{
		cout << "NO\n";
		return 0;
	}
	if (D - C == 1)
	{
		if (A > 0 || B > 0)
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		FOR(i, 0, C)
		{
			cout << "3 2 ";
		}
		cout << "3\n";
		return 0;
	}
	if (A - B == 1)
	{
		if (C > 0 || D > 0)
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		FOR(i, 0, B)
		{
			cout << "0 1 ";
		}
		cout << "0\n";
		return 0;
	}
	A--;
	ans.clear();
	ans.PB(0);
	if (work())
	{
		printans();
		return 0;
	}
	A++;
	B--;
	ans.clear();
	ans.PB(1);
	if (work())
	{
		printans();
		return 0;
	}
	B++;
	C--;
	ans.clear();
	ans.PB(2);
	if (work())
	{
		printans();
		return 0;
	}
	C++;
	D--;
	ans.clear();
	ans.PB(3);
	if (work())
	{
		printans();
		return 0;
	}
	D++;
	cout << "NO\n";
	return 0;
}