#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define e1 first
#define e2 second
typedef long long ll;
typedef pair <ll, ll> BONG;
typedef pair <BONG, BONG> LONG;
typedef unsigned long long ull;
const ll inf = 1e9+9;
const ll INF = 1e18+18;
const int mod = 1e9+7;

int n,m;
#define maxn 1000100
char s[maxn];
ll t[maxn][6];
//stan 1 - zero
//stan 2 - bomba 
//stan 3 - jedynka fulfilled
//stan 4 - jedynka niefulfilled
//stan 5 - dwojka
int main()
{
	scanf("%s", s+1);
	n = 1;
	while (s[n]) ++n;
	--n;
	bool wgl_sie_da = true;
	if (s[1] != '?')
	{
		if (s[1] == '2') wgl_sie_da = false;
		if (s[1] == '1') t[1][4] = 1;
		if (s[1] == '0') t[1][1] = 1;
		if (s[1] == '*') t[1][2] = 1;
	}
	else t[1][1] = t[1][2] = t[1][4] = 1;
	for (int i=2; i<=n; ++i)
	{
		if (s[i] != '?')
		{
			if (s[i] == '*') t[i][2] = t[i-1][4] + t[i-1][5] + t[i-1][2];
			if (s[i] == '0') t[i][1] = t[i-1][1] + t[i-1][3];
			if (s[i] == '2') t[i][5] = t[i-1][2];
			if (s[i] == '1')
			{
				t[i][3] = t[i-1][2];
				t[i][4] = t[i-1][1] + t[i-1][3];
			}
		} 
		else //we can choose
		{
			t[i][1] = t[i-1][1] + t[i-1][3];
			t[i][2] = t[i-1][2] + t[i-1][4] + t[i-1][5];
			t[i][3] = t[i-1][2];
			t[i][4] = t[i-1][1] + t[i-1][3];
			t[i][5] = t[i-1][2];
		}
		for (int j=1; j<=5; ++j)
		{
			while (t[i][j] >= mod) t[i][j] -= mod;
		}
	}
	ll wyn = t[n][1] + t[n][2] + t[n][3];
	if (wgl_sie_da) cout << (wyn % mod);
	else cout << 0;
}