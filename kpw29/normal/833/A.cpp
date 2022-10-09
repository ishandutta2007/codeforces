#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
int n, m, k;
const int MX = 1000010;
int sito[MX + 5];
vector <int> primes;

int main()
{
	boost;
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		ll a, b; 
		cin >> a >> b;
		ll ilo = a * b;
		ll x = 1, y = MX;
		while (x < y)
		{
			ll sr = (x + y)/2;
			if (sr * sr * sr < ilo) x = ++sr;
			else y = sr;
		}
		//cout << x << endl;
		bool odp = 1;
		if (x * x * x != ilo) odp = 0;
		else 
		{
			if (a % x != 0) odp = 0;
			if (b % x != 0) odp = 0;
		}
		
		if (odp) cout << "Yes\n";
		else cout << "No\n";
	}
}