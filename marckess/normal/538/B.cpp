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
int res = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s;
    for (char c : s) {
        c -= '0';
        res = max(res, int(c));
    }

    cout << res << endl;
    for (int i = 0; i < res; i++) {
        string a;
        for (char &c : s) {
            if (c == '0')
                a.push_back('0');
            else {
                a.push_back('1');
                c--;
            }
        }
        cout << stoi(a) << " ";
    }
    cout << endl;
    
    return 0;
}