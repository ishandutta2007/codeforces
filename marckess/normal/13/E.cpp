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

const int MX = 100005, SQ = 316;
int n, m, blo[MX], ult[MX], cnt[MX], a[MX], op, x, y;

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
    	scanf("%d", a+i);
    	blo[i] = i / SQ;
    }

    for (int i = n - 1; i >= 0; i--) {
    	int sig = i + a[i];
    	if (sig >= n || blo[i] != blo[sig]) {
    		ult[i] = i;
    		cnt[i] = 0;
    	} else {
    		ult[i] = ult[sig];
    		cnt[i] = cnt[sig] + 1;
    	}
    }

    while (m--) {
    	scanf("%d", &op);

    	if (op) {
    		int salt = 0, fin;
    		scanf("%d", &x);
    		x--;

    		while (x < n) {
    			salt += cnt[x] + 1;
    			fin = ult[x];
    			x = ult[x] + a[ult[x]];
    		}

    		printf("%d %d\n", fin + 1, salt);
    	} else {
    		int sig;
    		scanf("%d %d", &x, &y);
    		x--;

    		a[x] = y;
    		sig = x + a[x];
    		if (sig >= n || blo[x] != blo[sig]) {
    			ult[x] = x;
    			cnt[x] = 0;
    		} else {
    			ult[x] = ult[sig];
    			cnt[x] = cnt[sig] + 1;
    		}

    		for (int i = x - 1; i >= 0; i--) {
    			if (blo[i] != blo[x])
    				break;
    			
    			sig = i + a[i];
    			if (sig < n && blo[i] == blo[sig]) {
    				ult[i] = ult[sig];
    				cnt[i] = cnt[sig] + 1;
    			}
    		}
    	}
    }

    return 0;
}