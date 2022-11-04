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

const int MX = 200005;
int n, pila[MX], top = -1, t, s, res = 0, acu = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    pila[++top] = 1e9;

    while (n--) {
        cin >> t;

        if (t == 1) {
            cin >> s;
            while (pila[top] < s) {
                top--;
                res++;
            }
        } else if (t == 2) {
            res += acu;
            acu = 0;
        } else if (t == 3) {
            cin >> pila[++top];
            while (pila[top] < s) {
                top--;
                res++;
            }
        } else if (t == 4) {
            acu = 0;
        } else if (t == 5) {
            pila[++top] = 1e9;
        } else {
            acu++;
        }
    }

    cout << res << endl;

    return 0;
}