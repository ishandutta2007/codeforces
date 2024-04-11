#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 200005;
int n, izq[MX], der[MX];
string s;

bool isBalanced (string s) {
	int cn = 0;
	for (char c : s) {
		if (c == '(')
			cn++;
		else
			cn--;
			
		if (cn < 0)
			return 0;
	}
	return 1;
}

void main_() {
	cin >> n >> s;
	n *= 2;
	
	if (isBalanced(s)) {
		cout << 0 << endl;
		return;
	}
	
	int cn = 0;
	forn (i, n) {
		if (s[i] == '(')
			cn++;
		else
			cn--;
		izq[i] = cn;
	}
	
	cn = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == ')')
			cn++;
		else
			cn--;
		der[i] = cn;
	}
	
	int l = 0;
	while (izq[l] >= 0)
		l++;
	for (int i = l; i >= 0; i--)
		if (der[i] > der[l])
			l = i;
	
	int r = n - 1;
	while (der[r] >= 0)
		r--;
	for (int i = r; i < n; i++)
		if (izq[i] > izq[r])
			r = i;
	
	string t = s;
	reverse(t.begin() + l, t.begin() + r + 1);
	
	if (isBalanced(t)) {
		cout << 1 << endl;
		cout << l + 1 << " " << r + 1 << endl;
		return;
	}
	
	cout << 2 << endl;
	l = 0;
	forn (i, n)
		if (izq[i] > izq[l])
			l = i;
	
	cout << 1 << " " << l + 1 << endl;
	cout << l + 2 << " " << n << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}