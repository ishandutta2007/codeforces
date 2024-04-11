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

const int MX = 200005;
string s, t;
int izq[MX], der[MX], mx[MX], mn[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> s >> t;
    fill(mn, mn+MX, 1e9);
    for (int i = 0; i < s.size(); i++) {
        if (i) izq[i] = izq[i-1];
        if (izq[i] < t.size() && s[i] == t[izq[i]]) izq[i]++;
        mn[izq[i]] = min(mn[izq[i]], i);
    }
    mn[0] = -1;
    
    for (int i = s.size() - 1; i + 1; i--) {
        der[i] = der[i+1];
        if (der[i] < t.size() && s[i] == t[t.size() - 1 - der[i]]) der[i]++;
        mx[der[i]] = max(mx[der[i]], i);
    }
    mx[0] = s.size();
    
    int res = 0;
    for (int i = 0; i <= t.size(); i++) {
        res = max(res, mx[i] - mn[t.size() - i] - 1);
    }
    cout << res << endl;
 
	return 0;
}