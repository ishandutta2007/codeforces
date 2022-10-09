#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define root 1
#define maxn 300100
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
typedef pair <BONG, BONG> DONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
ll N,M,P,Q;

string s;
vector <int> p1, p2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s;
	int dl = s.length() - 1;
	for (int i=0; i<dl; ++i)
	{
		if (s[i] == 'A' && s[i+1] == 'B') p1.pb(i);
		if (s[i] == 'B' && s[i+1] == 'A') p2.pb(i);
	}
	
	if (p1.size() == 0 || p2.size() == 0)
	{
		puts("NO");
		return 0;
	}
	int wa = p1[0];
	int wb = p2[p2.size() - 1];
	if (wa + 1 < wb) 
	{
		puts("YES");
		return 0;
	}
		
	 wa = p1[p1.size() - 1];
	 wb = p2[0];
	if (wb + 1 < wa) 
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}