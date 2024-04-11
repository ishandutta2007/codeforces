#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;

int n, m, k;
int tab[maxn];
string s;

bool ok[maxn];
int A[maxn], B[maxn];


int main()
{
	boost;
	cin >> n >> s;
	FOR(i, 0, n-1) ok[i + 1] = s[i] - '0';
	FOR(i, 1, n) {
		cin >> A[i] >> B[i];
	}
	
	int res = 0;
	int tmp = 0;
	FOR(i, 1, n) tmp += ok[i];
	res = max(res, tmp); 
	FOR(step, 1, 1000000) {
		FOR(i, 1, n)
			if (step >= B[i] && ((step - B[i]) % A[i] == 0)) ok[i] ^= 1;
		
		tmp = 0;
		FOR(i, 1, n) tmp += ok[i];
		res = max(res, tmp); 
	}
	
	cout << res;
}