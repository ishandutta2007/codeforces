
// Problem : E1. Permutation Minimization by Deque
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/E1
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

void main_() {
	int n;
	deque<int> d;
	
	cin >> n;
	while (n--) {
		int p;
		cin >> p;
		
		if (d.empty() || p < d.front())
			d.push_front(p);
		else
			d.push_back(p);
	}
	
	while (d.size()) {
		cout << d.front() << " ";
		d.pop_front();
	}
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