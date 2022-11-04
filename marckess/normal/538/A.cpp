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
int n;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n - i; j++) {
            string a = s;
            a.erase(i, j);
            if (a == "CODEFORCES") {
                cout << "YES" << endl;
                return 0;
            }
        }

    cout << "NO" << endl;
    
    return 0;
}