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

const int MX = 100010;
int n, l, a[MX], b[MX];

bool esPos (int m) {
    for (int i = 0; i <= n; i++) b[i] = 0;
    b[0] = m;
    
    int i = 0, j = 1;
    while (i < n) {
        while (b[i]) {
            while (j <= n && b[j] == a[j]) j++;
            if (i + l < j) return 0;
            
            int d = min(b[i], a[j] - b[j]);
            b[i] -= d;
            b[j] += d;
        }
        i++;
        j = max(i+1, j);
    }
    
    return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
        cin >> n >> l;
        for (int i = 1; i < n; i++) cin >> a[i];
        a[n] = 2e9;
        
        int i = 0, j = 1e9+5, rep = 32;
        
        while (i + 1 < j) {
            int m = (ll(i)+j)/2;
            if (esPos(m)) i = m;
            else j = m-1;
        }
        
        if (esPos(j)) cout << j << endl;
        else cout << i << endl;

	return 0;
}