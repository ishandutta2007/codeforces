#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

stack<int> st;
string s;
int n, top = 1, res = 0, x;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    n *= 2;
    while (n--) {
        cin >> s;
        if ( s[0] == 'a' ) {
            cin >> x;
            st.push(x);
        } else {
            if ( st.size() ) {
                if ( st.top() == top ) {
                    st.pop();
                } else {
                    while ( st.size() )
                        st.pop();
                    res++;
                }
            }
            top++;
        }
    }

    cout << res << endl;

    return 0;
}