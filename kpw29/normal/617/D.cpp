#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef pair <PII, ll> PIIL;
typedef pair <int, ll> PIL;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000010

int tab[maxn], a, b, n, m, c, k;
int t[4][4];
PII wsp[4];
int main()
{	
	for (int i=1; i<=3; ++i) {
	  for (int j=1; j<=2; ++j)
	  {
		  scanf("%d", &t[i][j]);
		  
	  }
	 
	  wsp[i] = mp(t[i][1], t[i][2]);
  }
	if (t[1][1] == t[2][1] && t[1][1] == t[3][1]) OUT(1);
	if (t[1][2] == t[2][2] && t[1][2] == t[3][2]) OUT(1);
	//we need to sort them
	sort(wsp+1, wsp+3+1);
	if (wsp[1].e1 == wsp[2].e1)
	{
		//mogloby byc 2
		if (wsp[3].e2 <= wsp[1].e2 || wsp[3].e2 >= wsp[2].e2) OUT(2);
	}
	if (wsp[2].e1 == wsp[3].e1)
	{
		if (wsp[1].e2 <= wsp[2].e2 || wsp[1].e2 >= wsp[3].e2) OUT(2);
	}
	//printf("%d %d\n", wsp[3].e1, wsp[3].e2);
	for (int i=1; i<=3; ++i) swap(wsp[i].e1, wsp[i].e2);
	sort(wsp+1, wsp+3+1);
	if (wsp[1].e1 == wsp[2].e1)
	{
		//mogloby byc 2
		if (wsp[3].e2 <= wsp[1].e2 || wsp[3].e2 >= wsp[2].e2) OUT(2);
	}
	if (wsp[2].e1 == wsp[3].e1)
	{
		if (wsp[1].e2 <= wsp[2].e2 || wsp[1].e2 >= wsp[3].e2) OUT(2);
	}
	OUT(3);
	
}