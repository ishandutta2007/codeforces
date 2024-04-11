#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 7010;
int n, m, k, a, b, c;

bool odw[7010];
ll SCORE; int people;
ll wyn;
vector <int> top;
bool kraw[7010][7010];
ll A[maxn], B[maxn];

ll score[7010];
int DL;

int sum[7010];
bool rem[7010];
int stu = 0;

ll okej[7010];

int main()
{
	boost;
	cin >> n;
	ll sm = 0;
	FOR(i, 1, n) cin >> A[i];
	FOR(i, 1, n) cin >> B[i], sm += B[i];
	stu = n;
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			if (i == j) continue;
			if ((A[i] | A[j]) == A[j]) kraw[i][j] = 1, okej[i]++;
			else kraw[i][j] = 0;
		}
	}
	
	bool removed = true;
	FOR(steps, 0, n)
	{
		removed = false;
		FOR(i, 1, n)
		{
			if (rem[i]) continue;
			if (okej[i] == 0)
			{
				FOR(j, 1, n)
					if (!rem[j] && kraw[j][i]) okej[j]--;
					
				rem[i] = true;
				removed = 1;
				sm -= B[i];
				stu--;
				break;
			}
		}
		
		if (!removed) break;
	}
	
	if (stu > 1) cout << sm;
	else cout << 0;
}