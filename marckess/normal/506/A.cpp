#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
int dp[30005][605], a[30005];
int n, d, x;

int obtRes (int i, int j) {
    if (i > 30000)
        return 0;

    int &res = dp[i][j];
    if (res != -1)
        return res;

    res = a[i];
    int s = d + (j - 300);
    if (s <= 0)
        return res = 0;
    return res += max(
                    obtRes(i+s-1, j-1),
                max(obtRes(i+s, j),
                    obtRes(i+s+1, j+1))
                );
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 30005; i++)
        for (int j = 0; j < 605; j++)
            dp[i][j] = -1;

    cin >> n >> d;
    while (n--) {
        cin >> x;
        a[x]++;
    }

    cout << obtRes(d, 300) << endl;

    return 0;
}