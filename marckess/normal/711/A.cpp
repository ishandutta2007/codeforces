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

int n;
char c[1005][6];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> c[i];

    for (int i = 0; i < n; i++) {
    	if (c[i][0] == 'O' && c[i][1] == 'O')
    		c[i][0] = c[i][1] = '+';
    	else if (c[i][3] == 'O' && c[i][4] == 'O')
    		c[i][3] = c[i][4] = '+';
    	else
    		continue;

    	cout << "YES" << endl;
    	for (int i = 0; i < n; i++)
    		cout << c[i] << endl;
    	return 0;
    }

    cout << "NO" << endl;

    return 0;
}