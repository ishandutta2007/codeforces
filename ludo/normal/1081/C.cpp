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

const ll mod = 998244353;

ll cnk[4001][4001];

ll powmod(ll b, ll e){
	ll r = 1;
	while(e){ if (e&1) r = r*b%mod; e >>= 1; b = b*b%mod; } return r; }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
cin >>n >>m>>k;

	for (int i = 0; i <= 4000; i++) {
		cnk[i][0] = cnk[i][i] = 1;
		for (int j = 1; j < i; j++) {
			cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j]) % mod;
		}
	}

	ll ret = cnk[n - 1][k];

	ret = ret * powmod(m - 1, k) % mod;
	ret = ret * m % mod;

	cout << ret << endl;

	return 0;
}