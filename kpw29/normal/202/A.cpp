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
#define maxn 1000100
int n,m,k, a, b;
long long A, B;

vector <char> W;
char t[20];
bool check(vector <char> w)
{
	int dl = w.size();
	for (int i=0; i<dl; ++i) 
	  t[i + 1] = w[i];
	for (int i=1; i<=dl; ++i) 
	 if (t[i] != t[dl - i + 1]) return false;
	return true;
}
bool wieksze(vector <char> wyn, vector <char> W)
{
	int dl = min(wyn.size(), W.size());
	for (int i=0; i<dl; ++i) 
	  if (wyn[i] > W[i]) return true;
	  else if (W[i] > wyn[i]) return false;
	if (wyn.size() == dl) return false;
	return true;
}
int main()
{
	string s;
	cin >> s;
	int dl = s.length();
	int pot = (1 << dl);
	for (int i=0; i<pot; ++i)
	{
		vector <char> wyn;
		wyn.clear();
		int bits[15];
		int help = i;
		for (int j=0; j<dl; ++j)
		{
			if (help & 1) bits[j] = 1;
			else bits[j] = 0;
			help >>= 1;
		}
		for (int j=0; j<dl; ++j)
		  if (bits[j]) wyn.pb(s[j]);
		if (check(wyn) == false) continue;

		if (wieksze(wyn, W)) W = wyn;
	}
	for (int i=0; i<W.size(); ++i) printf("%c", W[i]);
	return 0;
}