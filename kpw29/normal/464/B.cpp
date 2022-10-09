#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
 
const int maxn = 10;
int arr[8][8];
int perm[8];
 
int oper[8][8];
 
inline ll sq(ll x) {return x * x; }
 
int output[8][8];
vector <PII> checks;
 
set <pair <PII, int>> sa;
 
void walk(int pos, ll value)
{
	if (pos == 8)
	{
		//entire check
		/*FOR(i, 0, 7) cout << perm[i] << ' ';
		cout << endl;
		FOR(i, 0, 7) {
			FOR(j, 0, 2) cout << oper[perm[i]][j] << ' ';
			cout << endl;
		}*/
		
		bool fail = false;
		for (auto u : checks)
		{
			ll val = 0;
			FOR(j, 0, 2) val += sq(oper[perm[u.e1]][j] - oper[perm[u.e2]][j]);
			if (val != value) fail = true;
		}
		
		FOR(a, 0, 7)
			FOR(b, a+1, 7)
			{
				ll val = 0;
				FOR(j, 0, 2) val += sq(oper[perm[a]][j] - oper[perm[b]][j]);
				if (val == 0) fail = true;
			}
		
		if (!fail)
		{
			FOR(i, 0, 7) 
			{
					int jed = oper[perm[i]][0];
					int dwa = oper[perm[i]][1];
					int trzy = oper[perm[i]][2];
					
					output[perm[i]][0] = jed;
					output[perm[i]][1] = dwa;
					output[perm[i]][2] = trzy;
			}
					
			cout << "YES\n";
			FOR(i, 0, 7) {
				FOR(j, 0, 2) cout << output[i][j] << ' ';
				cout << endl;
			}
			exit(0);
		}
	}
	else
	{
		
		FOR(j, 0, 2) oper[perm[pos]][j] = arr[perm[pos]][j];
		/*cout << "arr: " << pos << '(' << perm[pos] << ',' << perm[pos-1] <<  ") : ";
		FOR(j, 0, 2) cout << oper[perm[pos-1]][j] << ' ';
		cout << endl;*/
		
		do
		{
			ll val = 0;
			FOR(j, 0, 2) val += sq(oper[perm[pos]][j] - oper[perm[pos - 1]][j]);
			pair <PII, int> xd = mp(mp(oper[perm[pos]][0], oper[perm[pos]][1]), oper[perm[pos]][2]);
			if (val == value && sa.find(xd) == sa.end())
			{
				sa.insert(xd);
				walk(pos + 1, value);
				sa.erase(xd);
			}
			
		}while(next_permutation(oper[perm[pos]], oper[perm[pos]]+3));
	}
}
 
int main()
{
	checks = {{0, 3}, {0, 5}, {1, 6}, {2, 7}, {4, 7}};
	FOR(i, 0, 7) {
		FOR(j, 0, 2) cin >> arr[i][j];
		sort(arr[i], arr[i] + 3);
	}
	
	for (int i=0; i<8; ++i) perm[i] = i;
	//perm[0] = 0; perm[1] = 1; perm[2] = 4; perm[3] = 2;
	//perm[4] = 5; perm[5] = 3; perm[6] = 6; perm[7] = 7;
	do
	{
		//okay we know the permutation, lets reset
		FOR(i, 0, 7)
			FOR(j, 0, 2) oper[perm[i]][j] = arr[perm[i]][j];
		
		do
		{
			ll value = 0;
			FOR(j, 0, 2) value += sq(oper[perm[0]][j] - oper[perm[1]][j]);
			walk(2, value);
		}while(next_permutation(oper[perm[1]], oper[perm[1]] + 3));
	}while(next_permutation(perm, perm+8));
	
	cout << "NO";
}