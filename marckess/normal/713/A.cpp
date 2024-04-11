#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int t;
string s;
char op;
map<ll, int> mp;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> op >> s;

        for (char &c : s)
            c = (c - '0') % 2 + '0';
        reverse(s.begin(), s.end());
        while (s.size() < 18)
            s.push_back('0');

        if (op == '+')
            mp[stoll(s)]++;
        else if (op == '-')
            mp[stoll(s)]--;
        else
            cout << mp[stoll(s)] << endl;
    }

    return 0;
}