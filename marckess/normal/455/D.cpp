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

const int MX = 100'005, SQ = 316, MSQ = 321;

int n, a[MX], c[MSQ][MX], blo[MX], pos[MX], last = 0;
int ls[MSQ][MSQ], ini[MSQ], fin[MSQ];
int q, op, l, r, k, bl, br;

int erase (int id, int elem) {
	int it;
	if (elem >= 0) it = ini[id] + elem;
	else it = fin[id] + elem + MSQ;
	if (it >= MSQ) it -= MSQ;

	int x = ls[id][it];

	c[id][x]--;

	int sig = it + 1;
	if (sig >= MSQ) sig -= MSQ;

	while (sig != fin[id]) {
		ls[id][it] = ls[id][sig];
		it = sig;
		sig++;
		if (sig >= MSQ) sig = 0;
	}

	fin[id] = it;
	return x;
}

void insert (int id, int elem, int val) {
	int it = ini[id];
	int ant = it - 1;
	if (ant < 0) ant += MSQ;

	ini[id] = ant;
	c[id][val]++;

	for (int i = 0; i < elem; i++) {
		ls[id][ant] = ls[id][it];
		ant = it;
		it++;
		if (it >= MSQ) it = 0;
	}

	ls[id][ant] = val;
} 

void update () {
	insert(bl, pos[l], erase(br, pos[r]));

	for (int i = bl; i < br; i++)
		insert(i+1, 0, erase(i, -1));
}

int query () {
	int res = 0, it = ini[bl];

	if (bl == br) {
		for (int i = 0; it != fin[bl] && i <= pos[r]; i++) {
			if (pos[l] <= i && ls[bl][it] == k)
				res++;
			it++;
			if (it >= MSQ) it = 0;
		}

		return res;
	}


	for (int i = 0; it != fin[bl]; i++) {
		if (i >= pos[l] && ls[bl][it] == k)
			res++;
		it++;
		if (it >= MSQ) it = 0;
	}

	it = ini[br];
	for (int i = 0; it != fin[br] && i <= pos[r]; i++) {
		if (ls[br][it] == k)
			res++;
		it++;
		if (it >= MSQ) it = 0;
	}

	for (int i = bl + 1; i < br; i++)
		res += c[i][k];

	return res;
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    scanf(" %d ", &n);
    for (int i = 1, cn = 0; i <= n; i++, cn++) {
    	scanf(" %d ", a+i);

    	blo[i] = i / SQ;
    	if (blo[i] != blo[i-1])
    		cn = 0;
    	pos[i] = cn;

    	ls[blo[i]][fin[blo[i]]++] = a[i];
    	c[blo[i]][a[i]]++;
    }

    scanf("%d ", &q);
    while (q--) {
    	scanf("%d %d %d", &op, &l, &r);

    	l = (l + last - 1) % n + 1;
    	r = (r + last - 1) % n + 1;
    	if (l > r)
    		swap(l, r);
    	bl = blo[l];
    	br = blo[r];

    	if (op == 1) {
    		if (l != r)
    			update ();
    	} else {
    		scanf("%d ", &k);
    		k = (k + last - 1) % n + 1;

    		printf("%d\n", (last = query()));
    	}
    }

    return 0;
}