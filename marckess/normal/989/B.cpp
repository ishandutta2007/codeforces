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
char c[2005];
int p, n;
bool res;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> p >> s;

    for (int i = 0; i < n; i++)
        if (s[i] != '.' && !c[i%p])
            c[i%p] = s[i];

    res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '.') {
            if (s[i] != c[i%p])
                res = 1;
        } else {
            if (c[i%p]) {
                s[i] = 1 - (c[i%p] - '0') + '0';
                res = 1;
            } else {
                s[i] = '1';
                c[i%p] = '1';
            }
        }
    }

    if (res)
        cout << s << endl;
    else
        cout << "No" << endl;

    return 0;
}