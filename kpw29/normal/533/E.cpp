#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;

string s, t;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s >> t;
	ll wyn =0; int poz = -1;
	int pocz = 0;
	int kon = n-1;
	while (s[pocz] == t[pocz]) ++pocz;
	while (s[kon] == t[kon]) --kon;
	
	for (int i=0; i<n; ++i)
	{
		if (s[i] != t[i] && poz == -1) poz = i;
	}
	if (pocz == kon) cout << 2 << endl;
	else
	{
		wyn = 0;
		bool czy = true;
		for (int i=pocz; i<kon; ++i) 
		  if (s[i] != t[i+1]) czy = false;
		if (czy) ++wyn;
		czy = true;
		for (int i=pocz; i<kon; ++i)
		  if (t[i] != s[i+1]) czy = false;
		if (czy) ++wyn;
		cout << wyn << endl;
		  
	}
}