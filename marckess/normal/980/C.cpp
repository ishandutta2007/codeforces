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

const int MX = 100005;
int n, k;
int p;
int g[MX];
bitset<MX> bs;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(g, g+MX, -1);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p;

        if (g[p] != -1) {
            cout << g[p] << " ";
            for (int l = g[p]; l <= p; l++)
                bs[l] = 1;
            continue;
        }

        int j = p;
        while (j >= 0 && !bs[j] && p - j < k)
            j--;
        j++;

        for (int l = j; l < j + k; l++) {
            if (bs[l])
                break;
            g[l] = j;
        }

        for (int l = g[p]; l <= p; l++)
            bs[l] = 1;

        cout << g[p] << " ";
    }

    cout << endl;

    return 0;
}