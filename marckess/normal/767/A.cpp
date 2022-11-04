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

    int n, act, x;
    bitset<100005> bs;

    cin >> n;

    act = n;
    while (n--) {
        cin >> x;
        bs[x] = 1;

        while (act > 0 && bs[act]) {
            cout << act-- << " ";
        }

        cout << endl;
    }

    return 0;
}