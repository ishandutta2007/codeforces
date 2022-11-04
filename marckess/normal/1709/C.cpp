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

int n;
string s;

string lo () {
	int x = 0;
	string res = s;
	
	for (char c : res)
		if (c == '(')
			x++;
	
	for (char &c : res)
		if (c == '?') {
			if (2 * x == n)
				c = ')';
			else 
				c = '(', x++;
		}
	
	return res;
}

string hi () {
	string res = s;
	
	int x = 0, acu = 0;
	stack<int> st;
	
	for (char c : res)
		if (c == ')')
			x++;
	
	forn (i, n) {
		char &c = res[i];
		
		if (c == '(')
			acu++;
		else if (c == ')') {
			acu--;
			
			if (acu < 0) {
				int j = st.top();
				st.pop();
				x--;
				acu++;
				
				res[j] = '(';
				acu++;
			}
		} else if (acu > 0 && 2 * x < n) {
			st.push(i);
			x++;
			acu--;
			c = ')';
		} else {
			acu++;
			c = '(';
		}
	}
	
	return res;
}

void main_() {
	cin >> s;
	n = s.size();
	
	if (lo() == hi()) cout << "YES" << endl;
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