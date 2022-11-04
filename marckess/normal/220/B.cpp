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

const int MN = 1e5, SQ = round(sqrt(MN));
int n, m, a[100005], cub[100005] = {0};
int l[100005], r[100005], b[100005], q[100005], res[100005], acu = 0;

void cambia (int i, int k) {
	if (cub[a[i]] == a[i])
    	acu--;
    cub[a[i]] += k;
    if (cub[a[i]] == a[i])
    	acu++;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    FOR(i, n) {
    	cin >> a[i];
    	a[i] = min(a[i], MN+1);
    }

    FOR(i, m) {
    	cin >> l[i] >> r[i];
    	b[i] = l[i] / SQ;
    	q[i] = i;
    }
    sort (q, q+m, [&](int i, int j) {
    	if (b[i] == b[j])
    		return r[i] < r[j];
    	return b[i] < b[j];
    });

    int i = 0, j = -1;
    FOR (nd, m) {
    	int x = l[q[nd]]-1, y = r[q[nd]]-1;

    	while (i < x) {
    		cambia(i, -1);
    		i++;
    	}
    	while (i > x) {
    		i--;
    		cambia(i, 1);
    	}
    	while (j < y) {
    		j++;
    		cambia(j, 1);
    	}
    	while (j > y) {
    		cambia(j, -1);
    		j--;
    	}

    	res[q[nd]] = acu;
    }

    FOR (i, m) {
    	cout << res[i] << endl;
    }

    return 0;
}