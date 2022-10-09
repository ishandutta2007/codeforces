#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
int n, m, k, a, b, c, s;
int arr[maxn];
inline ll dist(ll x, ll y) {return abs(x - y); }
string s1, s2;

int main()
{
	boost;
	cin >> n >> s1 >> s2;
	int score = 0;
	FOR(i, 0, n-2)
	{
		if (s1[i] != s2[i] && s1[i+1] != s2[i+1] && s1[i] != s1[i + 1]) {
			++score;
			s1[i] = s2[i];
			s1[i + 1] = s2[i + 1];
		}
	}
	
	FOR(i, 0, n-1)
		if (s1[i] != s2[i]) ++score;
	
	cout << score;
}