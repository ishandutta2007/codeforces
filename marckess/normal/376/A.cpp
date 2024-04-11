#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;

    cin >> s;

    ll p = 0, res = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == '^')
            p = i;



    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '=' && s[i] != '^')
            res += (i - p) * (s[i] - '0');
    }

    if (res < 0)
        cout << "left" << endl;
    else if (res > 0)
        cout << "right" << endl;
    else
        cout << "balance" << endl;

    return 0;
}