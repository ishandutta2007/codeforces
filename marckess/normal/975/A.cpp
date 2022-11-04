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

set<ll> st;
int n;
string s;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> s;

        ll mk = 0;
        for (int i = 0; i < s.size(); i++)
            mk |= (1 << (s[i] - 'a'));

        st.insert(mk);
    }

    cout << st.size() << endl;

    return 0;
}