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

int n, sum, a, b, raiz;
int t[1000005];
vi res;
vvi hij;

int obtRes (int u) {
    int acu = t[u];

    for (int v : hij[u])
        acu += obtRes(v);

    if (acu == sum) {
        if (u != raiz)
            res.push_back(u);
        return 0;
    } else {
        return acu;
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    hij = vvi(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a >> t[i];
        sum += t[i];

        if (a)
            hij[a].push_back(i);
        else
            raiz = i;
    }

    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    sum /= 3;
    obtRes (raiz);

    if (res.size() < 2)
        cout << -1 << endl;
    else
        cout << res[0] << " " << res[1] << endl;

    return 0;
}