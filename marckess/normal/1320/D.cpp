#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
const int MX = 200005, LG = 20;
int n, m, q;
string s, t;
vi pos;
 
int sa[MX], lcp[MX], f[MX];
 
int t_sa[MX] = {0}, c[MX] = {0};
void countingSort (string &s, int ra[], int k) {
    int sum, n = s.size(), mx = max(300, n);
    memset(t_sa, 0, sizeof(t_sa));
    memset(c, 0, sizeof(c));
 
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
 
int t_ra[MX] = {0}, ra[MX] = {0};
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
 
int M[MX][LG], logTable[MX];
 
void pre(int n, int A[]) {
	for (int i = 2; i <= n; i++)
		logTable[i] = logTable[i >> 1] + 1;
	
	for (int i = 0; i < n; i++)
    	M[i][0] = A[i];
 
  	for(int j = 1; (1 << j) <= n; j++)
    	for(int i = 0; i + (1 << j) - 1 < n; i++)
			M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
}
 
int query (int i, int j) {
  if (i > j) return 0;
  int k = logTable[j - i + 1];
  return min(M[i][k], M[j - (1 << k) + 1][k]);
}
 
ii find (int l, int r) {
	auto it = lower_bound(all(pos), l);
	auto jt = upper_bound(all(pos), r);
 
	if (it == jt || jt == pos.begin()) return {-1, -1};
	jt--;
 
	return {int(it - pos.begin()), int(jt - pos.begin())};
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> t;
 
	for (int i = 0; i < n; i++)
		if (t[i] == '0')
			pos.pb(i);
 
	m = pos.size();
	for (int i = 0; i + 1 < m; i++)
		s.pb('0' + (pos[i + 1] - pos[i]) % 2);
 
	s.pb('0' - 1);
	obtSA(s);
	obtLCP(s);
	pre(m, lcp);
	for (int i = 0; i < m; i++)
		f[sa[i]] = i;
 
	#define no { cout << "No" << endl; continue; }
	#define yes { cout << "Yes" << endl; continue; }  
 
	cin >> q;
	while (q--) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
 
		l1--, l2--;
		if (l1 > l2) swap(l1, l2);
 
		if (l1 == l2) yes
 
		ii a = find(l1, l1 + len - 1);
		ii b = find(l2, l2 + len - 1);
 
		if (a.fi == -1 && b.fi == -1) yes
		if (a.fi == -1 || b.fi == -1) no
		if (a.se - a.fi != b.se - b.fi) no
 
		if ((pos[a.fi] - l1) % 2 != (pos[b.fi] - l2) % 2) no
		if ((l1 + len - pos[a.se]) % 2 != (l2 + len - pos[b.se]) % 2) no
		if (a.fi == a.se) yes
 
		if (f[a.fi] > f[b.fi]) swap(a, b);
		if (a != b && query(f[a.fi] + 1, f[b.fi]) < a.se - a.fi) no
 
		yes
	}
 
	return 0;
}