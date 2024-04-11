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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, a[105], res = 0;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i]; 

    for (int i = 1; i < n - 1; i++)
        if (!a[i] && a[i-1] && a[i+1]) {
            a[i+1] = 0;
            res++;
        }
    cout << res << endl;

    return 0;
}