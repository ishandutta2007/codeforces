#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

string s;

bool pos (char a, char b, char c) {
    vi v = {a, b, c}, w = {'A', 'B', 'C'};
    sort(ALL(v));
    return v == w;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s;
    for (int i = 1; i + 1 < s.size(); i++) {
        if (pos(s[i-1], s[i], s[i+1])) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}