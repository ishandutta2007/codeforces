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

int n, q[] = {0, 1, 2, 3}, res = 1e9;
char c[1005][1005], p[4][105][105];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int k = 0; k < 4; k++)
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			cin >> p[k][i][j];

   	while (next_permutation(q, q+4)) {
  		for (int i = 0; i < n; i++)
  			for (int j = 0; j < n; j++)
  				c[i][j] = p[q[0]][i][j];

  		for (int i = 0; i < n; i++)
  			for (int j = 0; j < n; j++)
  				c[i][j+n] = p[q[1]][i][j];

  		for (int i = 0; i < n; i++)
  			for (int j = 0; j < n; j++)
  				c[i+n][j] = p[q[2]][i][j];

  		for (int i = 0; i < n; i++)
  			for (int j = 0; j < n; j++)
  				c[i+n][j+n] = p[q[3]][i][j];

  		int a[2] = {0, 0}, b[2] = {0, 0};
  		for (int i = 0; i < 2*n; i++)
  			for (int j = 0; j < 2*n; j++) {
  				if (i % 2 == j % 2) {
  					if (c[i][j] == '0')
  						b[0]++;
  					else
  						a[1]++;
  				} else {
  					if (c[i][j] == '1')
  						b[1]++;
  					else
  						a[0]++;
  				}
  			}

  		res = min(res, min(a[0] + a[1], b[0] + b[1]));
   	}

   	cout << res << endl;

    return 0;
}