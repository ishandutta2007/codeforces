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

int n,m,a,b,c;
int t[110];
int nowe[110];

int main()
{
	boost;
	int wyn = 0;
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> t[i];
	for (int i=1; i<=n; ++i)
	  for (int j=i; j<=n; ++j)
	  {
		  int tmp_wyn = 0;
		  for (int help=1; help<=n; ++help)
		  {
		    if (help >= i && help <= j) nowe[help] = 1 - t[help];
		    else nowe[help] = t[help];
		    tmp_wyn += nowe[help];
		}
		wyn = max(wyn, tmp_wyn);
	  }
	  cout << wyn << endl;
}