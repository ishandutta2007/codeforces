#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

string s;
queue<char> q;
stack<char> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	int i = 0, j = s.size() - 1;
	while (i <= j) {
		if (i == j) {
			q.push(s[i]);
			break;
		} else if (i + 2 >= j) {
			q.push(s[i]);
			break;
		} else {
			if (s[i] == s[j]) {
				q.push(s[i]);
				st.push(s[j]);
				i++, j--;
			} else if (s[i] == s[j-1]) {
				q.push(s[i]);
				st.push(s[j-1]);
				i++, j -= 2;
			} else if (s[i+1] == s[j]) {
				q.push(s[i+1]);
				st.push(s[j]);
				i += 2, j--;
			} else {
				i++, j--;
			}
		}
	}

	while (q.size()) {
		cout << q.front();
		q.pop();
	}

	while (st.size()) {
		cout << st.top();
		st.pop();
	}
	cout << endl;

	return 0;
}