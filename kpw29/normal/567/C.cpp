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

int n,m,a,b,c,k;
ll N,M,A,B,C;
char s[3010][3010];
#define maxn 1000100
ll tab[maxn];
map <int , ll> mapa;
map <int, ll> mapa2;
int main()
{
	boost;
	cin >> n >> k;
	ll wyn = 0;
	for (int i=1; i<=n; ++i) 
	{
		cin >> a;
		if (a % k == 0)
		{
			int dziel = a / k;
			wyn += mapa2[dziel];
			mapa2[a] += mapa[dziel];	
			
			//cout << i << ' ' << dziel << ' '<<mapa[dziel] <<  ' ' << mapa2[dziel] << ' '<< wyn << endl;
		}
		mapa[a]++;
	}

	cout << wyn;
	
}