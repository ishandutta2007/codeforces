// Powered by CP Editor (https://cpeditor.org)

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

int a, b, c, d;
string s;

typedef priority_queue<int, vi, greater<int>> pq;

void greedy (int &c, pq &v, int s) {
	int t = 0;
	while (v.size() && c) {
		int x = v.top();
		v.pop();
		
		if (x < s) {
			continue;
		}
		
		c--;
		x -= 2;
		
		if (x >= s)
			v.push(x);
		else
			t += x;
	}
}

void main_() {
	cin >> a >> b >> c >> d >> s;
	int n = s.size();
	
	int x = a + c + d;
	int y = b + c + d;
	
	for (int c : s) {
		if (c == 'A') x--;
		if (c == 'B') y--;
	}
	
	if (x || y) {
		cout << "NO" << endl;
		return;
	}
	
	pq va[2], vb[2];
	int cn = 1;
	char fi = s[0];
	
	for (int i = 1; i < n; i++) {
		if (s[i - 1] != s[i]) {
			cn++;
		} else {
			if (cn > 1) {
				if (fi == 'A') {
					va[cn % 2].push(cn);
					//cout << "A" << " " << cn << endl;
				}
				if (fi == 'B') {
					vb[cn % 2].push(cn);
					//cout << "B" << " " << cn << endl;
				}
			}
			
			cn = 1;
			fi = s[i];
		}
	}
	
	if (cn > 1) {
		if (fi == 'A') {
			va[cn % 2].push(cn);
			//cout << "A" << " " << cn << endl;
		}
		if (fi == 'B') {
			vb[cn % 2].push(cn);
			//cout << "B" << " " << cn << endl;
		}
	}
	
	greedy(c, va[0], 2);
	greedy(c, va[1], 2);

	greedy(d, vb[0], 2);
	greedy(d, vb[1], 2);
	
	greedy(d, va[0], 3);
	greedy(d, va[1], 3);
	
	greedy(c, vb[0], 3);
	greedy(c, vb[1], 3);
	
	if (!c && !d) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}