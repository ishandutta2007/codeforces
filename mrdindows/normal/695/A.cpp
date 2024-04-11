//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <complex>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

using ll = long long;
using pii = pair<int, int>;
template<class T1, class T2, class T3> struct triple {
	T1 x; T2 y; T3 z;
};
using tri = triple<int, int, int>;
using trll = triple<ll, ll, ll>;
template<class T1, class T2, class T3>
bool operator<(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
	return t1.x < t2.x || (t1.x == t2.x && (t1.y < t2.y || t1.y == t2.y && t1.z < t2.z));
}

#define eps 1e-9
#define bs 1000000007
const int mod = 1000000007;
const int INF = 1000111000;
const ll LLINF = 1000111000111000111LL;
const double PI = acos(-1.0);
#define bsize 256

#define all(v) (v).begin(), (v).end()
#define FI(n) for (int i = 0; i < n; ++i)
#define FJ(n) for (int j = 0; j < n; ++j)
#define FK(n) for (int k = 0; k < n; ++k)
#define FREIN(file) freopen(file, "rt", stdin)
#define FREOUT(file) freopen(file, "wt", stdout)
#define sqr(x) ((x)*(x))

#define DB(n) cerr<<#n<<" = "<<(n)<<" "
#define DBN(n) cerr<<#n<<" = "<<(n)<<"\n"

int gcd(int x, int y) { while (y) { x %= y, swap(x, y); } return y; }
ll gcd(ll x, ll y) { while (y) { x %= y, swap(x, y); } return y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll powmod(ll x, ll n, const int mod) {
	ll res = 1; while (n)
	{
		if (n & 1) res = res * x % mod; n /= 2; x = x * x % mod;
	} return res;
}

int n, k;
double prob[200];
double dp[1 << 20];
double sum[1 << 20];
double ans[22];

int count_bits(int x)
{
	if (x == 0)
		return 0;
	return count_bits(x / 2) + x % 2;
}

int flag;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> prob[i];
	}

	for (int mask = 0; mask < (1 << n); mask++)
	{
		double s = 0;
		for (int i = 0; i < n; i++)
		{
			if (mask&(1 << i))
				s += prob[i];
		}
		sum[mask] = s;
	}

	dp[0] = 1;

	for (int mask = 0; mask < (1 << n); mask++)
	{
		int qb = count_bits(mask);
		if (qb > k)
			continue;
		if (dp[mask]<1e-100)
			continue;
		if (qb == k)
			flag = 1;
		double rem_sum = 1.0 - sum[mask];
		if (rem_sum < 1e-6)
			continue;
		for (int i = 0; i < n; i++)
		{
			if (mask&(1 << i))
				continue;
			double chance_move = dp[mask] * prob[i] / rem_sum;
			dp[mask | (1 << i)] += chance_move;
		}
	}

	if (flag == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (prob[i] < 1e-6)
				ans[i] = 0;
			else
				ans[i] = 1;
		}
	}
	else
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			if (count_bits(mask) == k)
			{
				for (int i = 0; i < n; i++)
				{
					if (mask&(1 << i))
						ans[i] += dp[mask];
				}
			}
		}
	}

	cout.precision(12);
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		cout << fixed << ans[i];
	}
	cout << endl;

	return 0;
}