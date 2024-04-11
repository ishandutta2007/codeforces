
// Problem : D. Strange LCS
// Contest : Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL : https://codeforces.com/contest/1588/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

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

int n, mem[52][1 << 10], pos[10][52][2];
string s[10];

int dp (int i, int mk) {
	int &res = mem[i][mk];
	if (res != -1) return res;
	res = 0;
	
	forn (j, 52) {
		int f = 1, sig = 0;
		
		forn (k, n) {
			int act = pos[k][i][bool(mk & (1 << k))];
			
			if (pos[k][j][0] > act) {
			} else if (pos[k][j][1] > act) {
				sig |= 1 << k;
			} else {
				f = 0;
			}
		}
		
		if (f) {
			res = max(res, dp(j, sig) + 1);
		}
	}
	
	return res;
}

void rec (int i, int mk) {
	if (i < 26) cout << char('a' + i);
	else cout << char('A' + (i - 26));
	
	int res = dp(i, mk);
	if (res == 0) return;
	
	forn (j, 52) {
		int f = 1, sig = 0;
		
		forn (k, n) {
			int act = pos[k][i][bool(mk & (1 << k))];
			
			if (pos[k][j][0] > act) {
			} else if (pos[k][j][1] > act) {
				sig |= 1 << k;
			} else {
				f = 0;
			}
		}
		
		if (f) {
			if (res == dp(j, sig) + 1) {
				return rec(j, sig);	
			}
		}
	}
}

void main_() {
	cin >> n;
	
	memset(mem, -1, sizeof(mem));
	forn (i, n) {
		cin >> s[i];
		
		memset(pos[i], -1, sizeof(pos[i]));
		
		forn (j, s[i].size()) {
			int c = s[i][j];
			
			if ('a' <= c && c <= 'z') c -= 'a';
			else c = (c - 'A') + 26;
			
			if (pos[i][c][0] == -1) pos[i][c][0] = j;
			else pos[i][c][1] = j;
		}
	}
	
	int res = 0;
	char ini;
	
	forn (i, 52) {
		int f = 1;
		forn (j, n)
			f &= pos[j][i][0] != -1;
			
		if (!f) continue;
		
		int d = dp(i, 0) + 1;
		if (d > res) {
			res = d;
			ini = i;
		}
	}
	
	cout << res << endl;
	if (res) rec(ini, 0);
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}