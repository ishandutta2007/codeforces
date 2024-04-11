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

const int MX = 5000;
int n, a[MX], q, l, r;

int val[MX][MX], dp[MX][MX];

int obtVal (int i, int j) {
	if (i == j)
		return a[i];

	int &res = val[i][j];
	if (res != -1)
		return res;

	return res = obtVal(i, j-1) ^ obtVal(i+1, j);
}

int obtRes (int i, int j) {
	if (i > j)
		return 0;

	int &res = dp[i][j];
	if (res != -1)
		return res;

	res = obtVal(i, j);
	return res = max(res, max(obtRes(i, j-1), obtRes(i+1, j)));
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < MX; i++)
    	for (int j = 0; j < MX; j++)
    		dp[i][j] = val[i][j] = -1; 
    
    //cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    	//cin >> a[i];
    	scanf("%d", a+i);

    //cin >> q;
    scanf("%d", &q);
    while (q--) {
    	//cin >> l >> r;
    	scanf("%d %d", &l, &r);
    	//cout << obtRes (l-1, r-1) << endl;
    	printf("%d\n", obtRes(l-1, r-1));
    }

    return 0;
}