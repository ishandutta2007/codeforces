#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
    int mx = 0, a = 0, b = 0, x = 1;
    set<int> st;

    cin >> n;
    m = n;

    for (int i = 2; i <= n; i++) {
        int pw = 0;
        while (n % i == 0) {
            n /= i;
            pw++;
        }
        mx = max(mx, pw);
        if (pw) st.insert(pw);
        if (pw) x *= i; 
    }

    if (st.size() == 1) {
        int y = *st.begin();
        if (y - (y & -y) == 0) {
            int res = 0;
            while (y > 1) {
                y /= 2;
                res++;
            }
            cout << x << " " << res << endl;
            return 0;
        }
    }

    if (x == m) cout << x << " " << 0 << endl;
    else {
        int m = 1, l = 0;
        while (m < mx) {
            m *= 2;
            l++;
        }
        cout << x << " " << l+1 << endl;
    }

	return 0;
}