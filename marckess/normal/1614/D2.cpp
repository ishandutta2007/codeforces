#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 20000005;
int n, bs[MX], cn[MX];
ll dp[MX];
vi prime;
 
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch) && ch !='-') ch = gc();
        bool neg = 0;
        if(ch == '-') { neg = 1; ch = gc(); }
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
        if(neg) { x = -x; }
    }
} using io::read;
 
void main_() {
	read(n);
	
	forn (i, n) {
		int a;
		read(a);
		
		cn[a]++;
	}
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			prime.pb(i);
			
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
		}
	
	for (int d = 1; d < MX; d++) 
		for (int i = 2 * d; i < MX; i += d)
			cn[d] += cn[i];
		
	for (int d = 1; d < MX; d++)
		for (int p : prime) {
			int i = d * p;
			if (i > MX) break;
			
			dp[i] = max(dp[i], dp[d] + 1ll * d * (cn[d] - cn[i]));
		}
	
	ll res = 0;
	for (int i = 1; i < MX; i++)
		res = max(res, dp[i] + 1ll * i * cn[i]);
	cout << res << endl;
}
 
 
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}