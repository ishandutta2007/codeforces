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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 200100;
ll A[maxn], x[maxn], B[maxn], t;
int n;
int canLast[maxn];

inline int query(int x, int y) {
	if (x > y) return 0;
	return canLast[y] - canLast[x - 1];
}

bool check()
{
	FOR(i, 2, n)
		if (A[i] + t <= B[i - 1]) canLast[i] = canLast[i - 1] + 0;
		else canLast[i] = canLast[i-1] + 1;
	
	FOR(i, 1, n-1)
	{
		if (query(i + 1, x[i]) > 0) return 0;
		if (x[i] != n && query(i + 1, x[i] + 1) == 0) return 0;
	}
	return 1;
}

int main()
{
	boost;
	cin >> n >> t;
	FOR(i, 1, n) cin >> A[i];
	FOR(i, 1, n) cin >> x[i];
	
	for (int i=n; i>0; --i)
	{
		if (x[i] < i) OUT("No");
		if (i > 1 && x[i] < x[i - 1]) OUT("No");
	}
	
	B[n] = 3000000000000000000LL;
	FOR(i, 2, n)
	{
		if (x[i] == x[i-1])
		{
			//moze przejsc o jedno w lewo
			B[i - 1] = max(B[i - 2] + 1, A[i] + t); //przynajmniej tyle
		}
		else
		{
			//nie moze przejsc o jedno w lewo
			B[i - 1] = A[i] + t - 1;
			B[i - 1] = min(max(B[i - 2] + 1, A[i - 1] + t), B[i - 1]);
			
		}
		if (B[i - 2] >= B[i - 1]) OUT("No");
		if (B[i - 1] >= 3000000000000000000LL) OUT("No");
	}

	if (!check()) OUT("No");
		
	cout << "Yes\n";
	FOR(i, 1, n) cout << B[i] << ' ';
}