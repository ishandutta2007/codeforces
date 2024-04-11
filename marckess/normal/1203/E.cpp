#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 150005;
int n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n; i++) {
        if ((i && a[i] > 1 && a[i-1] + 1 < a[i]) || (!i && a[i] > 1)) {
            a[i]--;
        } else if (i && (a[i-1] == a[i] || a[i-1] - 1 == a[i])) {
            a[i]++;
        }
    }
    
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    cout << a.size() << endl;
 
	return 0;
}