#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

#define maxn 1000100
int n, m, k, a, b, c;
PP rec[maxn];
vector <int> v[maxn];
int col[maxn];
int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) 
	{
		cin >> rec[i].e1.e1 >> rec[i].e1.e2 >> rec[i].e2.e1 >> rec[i].e2.e2;
		rec[i].e1.e1 += inf;
		rec[i].e1.e2 += inf;
		if (rec[i].e1.e1 % 2 == 0 && rec[i].e1.e2 % 2== 0) col[i] = 1;
		if (rec[i].e1.e1 % 2 == 0 && rec[i].e1.e2 % 2== 1) col[i] = 2;
		if (rec[i].e1.e1 % 2 == 1 && rec[i].e1.e2 % 2== 0) col[i] = 3;
		if (rec[i].e1.e1 % 2 == 1 && rec[i].e1.e2 % 2== 1) col[i] = 4;
	}
	cout << "YES\n";
	FOR(i, 1, n) cout << col[i] << "\n";
}