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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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
#define maxn 1001000
int n, m,k, a, b, c;
int tab[maxn];

int main()
{
	int v1, t1, v2, t2, s;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int w1 = 2 * t1 + s * v1;
	int w2 = 2 * t2 + s * v2;
	if (w1 == w2) cout << "Friendship";
	if (w1 < w2) cout << "First";
	if (w1 > w2) cout << "Second";
}