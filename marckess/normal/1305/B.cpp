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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 200005;
string s;
int n;
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	int i = 0, j = n - 1;
	while (i <= j) {
		if (s[i] == '(' && s[j] == ')') {
			st.insert(i);
			st.insert(j);
			i++, j--;
		} else if (s[i] != '(') {
			i++;
		} else if (s[j] != ')') {
			j--;
		}
	}

	if (st.size()) {
		cout << 1 << endl << st.size() << endl;
		for (int r : st)
			cout << r + 1 << " ";
		cout << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}