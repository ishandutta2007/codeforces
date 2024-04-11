#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, k, a[105][105], b[105][105];
char c[105][105];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> c[i];
        
        for (int i = 0; i < n; i++) {
            int ant = -1;
            for (int j = 0; j < n; j++) {
                if (c[i][j] == '.') {
                    if (ant == -1) ant = j;
                    if (j-k+1 >= ant) a[i][j-k+1]++, a[i][j+1]--;
                } else {
                    ant = -1;
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            int ant = -1;
            for (int i = 0; i < n; i++) {
                if (c[i][j] == '.') {
                    if (ant == -1) ant = i;
                    if (i-k+1 >= ant) b[i-k+1][j]++, b[i+1][j]--;
                } else {
                    ant = -1;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                a[i][j] += a[i][j-1];
        for (int j = 0; j < n; j++)
            for (int i = 1; i < n; i++)
                b[i][j] += b[i-1][j];
        
        int res = -1, x = 1, y = 1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[i][j] == '.')
                    if (a[i][j] + b[i][j] > res) {
                        res = a[i][j] + b[i][j];
                        x = i+1, y = j+1;
                    }
                    
        cout << x << " " << y << endl;

	return 0;
}