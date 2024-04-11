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
ll a[100005];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1e18;
    a[n+1] = 1e18;

    for (int i = 1; i <= n; i++) {
        cout << min(a[i] - a[i-1], a[i+1] - a[i]) << " ";
        cout << max(a[i] - a[1], a[n] - a[i]) << endl;
    }

    return 0;
}