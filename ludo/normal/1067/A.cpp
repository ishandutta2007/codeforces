#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxn = 1e5 + 1;
const int mod = 998244353;

inline int add(int a, int b) { return (a += b) >= mod ? (a - mod) : a; }
inline int isadd(int &a, int b) { return (a += b) >= mod ? (a -= mod) : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? (a + mod) : a; }
inline int issub(int &a, int b) { return (a -= b) < 0 ? (a += mod) : a; }

int n, a[maxn];

int satpf[maxn][201];
int unspf[maxn][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	REP(i, n) cin >> a[i + 1];

	// a[0] = 1
	/* for (int v = 1; v <= 200; v++) {
		satpf[0][v] = 1;
		unspf[0][v] = 0;
	}
	*/

	for (int v = 1, ways = 0; v <= 200; v++) {
		ways += (a[1] == -1 || v == a[1]);
		unspf[1][v] = ways;
		satpf[1][v] = 0;
	}

	for (int i = 2; i <= n; i++) {
		satpf[i][0] = unspf[i][0] = 0;
		for (int v = 1; v <= 200; v++) {
			int incsat = 0;
			int incuns = 0;
			if (a[i] == -1 || a[i] == v) {
				// calc incsat, incuns

				isadd(incuns, satpf[i - 1][v - 1]);
				isadd(incuns, unspf[i - 1][v - 1]);

				isadd(incsat, sub(satpf[i - 1][200], satpf[i - 1][v - 1]));
				isadd(incsat, sub(unspf[i - 1][v], unspf[i - 1][v - 1]));
			}
			satpf[i][v] = add(satpf[i][v - 1], incsat);
			unspf[i][v] = add(unspf[i][v - 1], incuns);
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int v = 1; v <= 10; v++) {
			cout << satpf[i][v] << "," << unspf[i][v] << " ";
		}
		cout << endl;
	}
	*/


	int ret = satpf[n][200];
	// for (int v = 1; v <= 200; v++) isadd(ret, satpf[n][v]);
	// answer has all satisfied ends
	cout << ret << endl;
	return 0;
}