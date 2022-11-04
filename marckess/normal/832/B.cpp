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
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

bitset<30> gc;
string s, t;
int n;

bool isPos() {
    int i = 0, j = 0;
    while ( i < s.size() && j < t.size() ) {
        if ( s[i] == t[j] )
            i++, j++;
        else if ( s[i] == '?' ) {
            if ( !gc[t[j]-'a'] )
                return false;
            i++, j++;
        }
        else if ( s[i] == '*' ) {
            while ( s.size() - i <= t.size() - j ) {
                if ( gc[t[j]-'a'] )
                    return false;
                j++;
            }
            i++;
        }
        else return false;
    }
    return (i == s.size() && j == t.size()) || j == t.size() && i == s.size() - 1 && s[i] == '*';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    for (int i = 0; i < s.size(); i++)
        gc[s[i]-'a'] = 1;

    cin >> s >> n;

    while (n--) {
        cin >> t;
        if (isPos())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}