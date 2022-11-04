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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, k, id;
deque<int> q;
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	while (n--) {
		cin >> id;
		if (st.count(id)) continue;
		if (q.size() == k) {
			st.erase(q.back());
			q.pop_back();
		}
		q.push_front(id);
		st.insert(id);
	}

	cout << q.size() << endl;
	while (q.size()) {
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << endl;

	return 0;
}