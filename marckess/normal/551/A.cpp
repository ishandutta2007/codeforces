#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    vi v, con;

    cin >> n;
    v = vi(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        con.push_back(v[i]);
    }

    sort (con.begin(), con.end(), greater<int>());

    for (int i = 0; i < n; i++)
        cout << lower_bound(con.begin(), con.end(), v[i], greater<int>()) - con.begin() + 1
             << " ";
    cout << endl;

    return 0;
}