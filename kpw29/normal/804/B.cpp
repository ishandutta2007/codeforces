#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, k, c;
ll A = 0, B = 0;
#define maxn 1000100
int tab[maxn];
string s;
int main()
{
	boost;
	cin >> s;
	n = s.length();
	A = 0, B = 0;
	ll res = 0;
	for (int i=n-1; i>=0; --i)
	{
		if (s[i] == 'b') ++B;
		else
		{
			res += B;
			res %= mod;
			B *= 2;
			B %= mod;
		}
	}
	cout << (res % mod);
	
	
}