#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,k,a,b,c,x ,y;
ll N,M,K,A,B,C;
int T;
int t[1010];

int solve(string s)
{
	int dl = s.length();
	int straz, cuk;
	for (int i=0; i<dl; ++i)
	{
		if (s[i] == 'G') straz = i;
		if (s[i] == 'S') cuk = i;
	}
	if (straz > cuk) return inf;
	t[cuk - straz]++;
	return 0;
}
int main()
{
	boost;
	cin >> n >> m;
	int wyn = 0;
	while (n--)
	{
		string s;
		cin >> s;
		wyn = max(wyn, solve(s));
	}
	if (wyn == inf) OUT("-1");
	int moves = 0;
	for (int i=1; i<=m; ++i) moves += (t[i])?1:0;
	printf("%d", moves);
}