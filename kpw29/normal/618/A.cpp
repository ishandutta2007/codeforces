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
int tab[maxn];
int DL = 0;
void add(int x) {
	tab[++DL] = x;
	while (tab[DL] == tab[DL-1]) --DL, tab[DL]++;
}
int main()
{
	tab[0] = -1;
	cin >> n;
	for (int i=1; i<=n; ++i) add(1);
	for (int i=1; i<=DL; ++i) printf("%d ", tab[i]);
}