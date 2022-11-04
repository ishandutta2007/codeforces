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

const int MX = 100005, SQ = 317, MN2 = 1048576;
int n, m, k, a[MX], l[MX], r[MX], q[MX], blo[MX];
ll suf[MN2] = {0}, pre[MN2] = {0}, acu = 0, res[MX];
int osuf = 0, opre = 0, tot = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
 	cin >> n >> m >> k;
 	for (int i = 1; i <= n; i++)
 		cin >> a[i];

 	for (int i = 0; i < m; i++) {
 		cin >> l[i] >> r[i];
 		blo[i] = l[i] / SQ;
 	}

 	iota(q, q+m, 0);
 	sort(q, q+m, [&] (int a, int b) {
 		if (blo[a] != blo[b])
 			return blo[a] < blo[b];
 		return r[a] < r[b];
 	});

 	int i = 1, j = 0;
 	for (int it = 0; it < m; it++) {
 		int u = q[it];

 		while (i < l[u]) {
 			acu -= pre[k ^ opre];

 			opre ^= a[i];
 			pre[opre]--;
 			suf[tot ^ osuf]--;
 			tot ^= a[i];

 			i++;
 		}

 		while (i > l[u]) {
 			i--;

 			pre[opre]++;
 			opre ^= a[i];
 			tot ^= a[i];
 			suf[tot ^ osuf]++;

 			acu += pre[opre ^ k];
 		}

 		while (j < r[u]) {
 			j++;

 			suf[osuf]++;
 			osuf ^= a[j];
 			tot ^= a[j];
 			pre[tot ^ opre]++;

 			acu += suf[osuf ^ k];
 		}

 		while (j > r[u]) {
 			acu -= suf[osuf ^ k];

 			osuf ^= a[j];
 			suf[osuf]--;
 			pre[tot ^ opre]--;
 			tot ^= a[j];

 			j--;
 		}
 		
 		res[u] = acu;
 	}

 	for (int i = 0; i < m; i++) 
 		cout << res[i] << endl;

    return 0;
}