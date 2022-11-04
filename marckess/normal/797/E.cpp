#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005, SQ = 317;
int n, q, p, k, a[MX], dp[SQ][MX];

int obtRes (int j, int i) {
	if (i >= n)
		return 0;

	int &res = dp[j][i];
	if (res != -1)
		return res;
	return res = obtRes(j, i + a[i] + j) + 1;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < SQ; i++)
    	for (int j = 0; j < MX; j++)
    		dp[i][j] = -1;

    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];

    cin >> q;
    while (q--) {
    	cin >> p >> k;
    	p--;

    	if (k < SQ) {
    		cout << obtRes(k, p) << endl;
    	} else {
    		int res = 0;

    		while (p < n) {
    			res++;
    			p += a[p] + k;
    		}

    		cout << res << endl;
    	}
    }

    return 0;
}