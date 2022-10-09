#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define root 1
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <ld, ld> DONG;
typedef pair <BONG, BONG> PAIR;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,d,k;
ll N,M,P,Q,A,C;
#define maxn 1000100
int tab[1010][1010];
int pos[maxn];
int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=n; ++j) cin >> tab[i][j];
	  
	for (int i=1; i<=n; ++i)
	{
		int l = 0;
		for (int k=1; k<=n; ++k) {
			int m = 0;
			for (int j=1; j<=n; ++j)
			  if (k != j && pos[j] == 0 && tab[k][j] > i) ++m;
			if (pos[k] == 0 && m <= 0 && l <= 0) pos[k] = i, ++l;
		}
		
	}
	
	for (int i=1; i<=n; ++i) {
	  printf("%d ", pos[i]);
  }
	
}