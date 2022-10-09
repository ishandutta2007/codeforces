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
int n,m;
int t[milion];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int pol = n/2;
	for (int i=1; i<=pol; ++i) t[i] = 2*i;
	for (int i=pol+1; i<=n; ++i)
	{
		int help = i - pol;
		t[i] = 2 * help - 1;
	}
	if (n > 3 || n == 1)
	{
		cout << n << endl;
		for (int i=1; i<=n; ++i) cout << t[i] << ' ';
	}
	else if (n == 3)
	{
		cout << '2' << endl;
		cout << "1 3" << endl;
	}
	else if (n == 2)
	{
		cout << '1' << endl;
		cout << "1" << endl;
	}
	
	
	
}