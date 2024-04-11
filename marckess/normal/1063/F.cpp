#include <bits/stdc++.h>
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()
using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

const int MX = 500005, LG = 20, inf = 1000000005;
int sa[MX], lcp[MX], f[MX];

int t_sa[MX], c[MX];
void countingSort (string &s, int ra[], int k) {
	memset(t_sa, 0, sizeof(t_sa));
	memset(c, 0, sizeof(c));
    int sum, n = s.size(), mx = max(300, n);

    for (int i = 0; i < n; i++)
        c[i+k<n?ra[i+k]:0]++;

    for (int i = sum = 0; i < mx; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (int i = 0; i < n; i++)
        t_sa[c[sa[i]+k<n?ra[sa[i]+k]:0]++] = sa[i];

    for (int i = 0; i < n; i++) sa[i] = t_sa[i];
}

int t_ra[MX], ra[MX];
void obtSA (string &s) {
    int r, n = s.size();

    for (int i = 0; i < n; i++) ra[i] = s[i];
    for (int i = 0; i < n; i++) sa[i] = i;

    for (int k = 1; k < n; k <<= 1) {
        countingSort(s, ra, k);
        countingSort(s, ra, 0);

        t_ra[s[0]] = r = 0;

        for (int i = 1; i < n; i++)
            if (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])
                t_ra[sa[i]] = r;
            else
                t_ra[sa[i]] = ++r;

        for (int i = 0; i < n; i++) ra[i] = t_ra[i];
        if (ra[sa[n-1]] == n-1) break;
    }
}

int phi[MX], plcp[MX];
void obtLCP (string &s) {
    int n = s.size();

    phi[sa[0]] = -1;
    for (int i = 1; i < n; i++) phi[sa[i]] = sa[i-1];

    for (int i = 0, l = 0; i < n; i++) {
        if (phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }

        while (s[i+l] == s[phi[i]+l]) l++;

        plcp[i] = l;
        l = max(l-1, 0);
    }

    for (int i = 0; i < n; i++) lcp[i] = plcp[sa[i]];
}

int n, dp[MX], st[4 * MX], p[MX], res = 1;

void build (int i, int j, int pos) {
	st[pos] = -inf;
	
	if (i == j) {
		p[i] = pos;
		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int x, int k) {
	int pos = p[x];
	st[pos] = k;
	pos /= 2;

	while (pos) {
		st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
		pos /= 2;
	}
}

int query (int i, int j, int pos, int a, int b) {
	if (b < i || j < a) return -inf;
	if (a <= i && j <= b) return st[pos];
	int m = (i + j) / 2;
	return max(
		query(i, m, pos * 2, a, b),
		query(m + 1, j, pos * 2 + 1, a, b)
	);
}

int M[MX][LG], logTable[MX];

void pre (int n, int A[]) {
	for(int i = 2; i <= n; i++)
		logTable[i] = logTable[i >> 1] + 1;

	for(int i = 0; i < n; i++)
    	M[i][0] = A[i];
	
	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 0; i + (1 << j) - 1 < n; i++)
			M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
}

int query (int i,int j){
	if(i > j) return 0;
	int k = logTable[j - i + 1];
	return min(M[i][k], M[j - (1 << k) + 1][k]);
}

string s;
ii find (int pos, int k) {
	ii res(pos, pos);

	int i = 1, j = pos, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (query(m + 1, pos) >= k) j = m;
		else i = m;
	}
	res.fi = j;

	i = pos, j = n, rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (query(pos + 1, m) >= k) i = m;
		else j = m;
	}
	res.se = i;

	return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> s;
    
    s = s + "#";
    obtSA(s);
    obtLCP(s);
    pre(n + 3, lcp);
    build(1, n, 1);

    for (int i = 1; i <= n; i++)
    	f[sa[i]] = i;

    for (int i = n - 1; i >= 0; i--) {
    	dp[i] = dp[i + 1] + 1;

    	while (dp[i] > 1) {
    		ii p = find(f[i], dp[i] - 1);
			if (query(1, n, 1, p.fi, p.se) >= dp[i] - 1)
				break;
    		
    		p = find(f[i+1], dp[i] - 1);
			if (query(1, n, 1, p.fi, p.se) >= dp[i] - 1)
				break;

    		dp[i]--;
    		if (i + dp[i] < n)
    			update(f[i + dp[i]], dp[i + dp[i]]);
    	}

    	res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}