#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
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
char s[20];
int pot[20];
int main()
{
	scanf("%s", s+1);
	int n = 1;
	while (s[n]) ++n;
	--n;pot[0] = 1;
	for (int i=1; i<=n; ++i) pot[i] = 2 * pot[i-1];
	int wyn = pot[n] - 2;
	for (int i=1; i<=n; ++i)
	{
		if (s[i] == '7') wyn += pot[n - i];
	}
	printf("%d", ++wyn);
}